#include "ClapTrap.h"

#include <iostream>

#include <climits>

/* ############################################################
 * #				CONSTRUCTORS & DESTRUCTORS				  #
 * ############################################################ */

ClapTrap::ClapTrap()
	: name("Default"),
	  hit_points(10U),
	  energy_points(10U),
	  attack_damage(0U)
{
	std::cout << "ClapTrap default constructor is called\n";
}

ClapTrap::ClapTrap(const std::string &itsName)
	: name(itsName),
	  hit_points(10U),
	  energy_points(10U),
	  attack_damage(0U)
{
	std::cout << "ClapTrap constructor is called\n";
}

ClapTrap::ClapTrap(const ClapTrap &obj)
	: name(obj.name),
	  hit_points(obj.hit_points),
	  energy_points(obj.energy_points),
	  attack_damage(obj.attack_damage)
{
	std::cout << "ClapTrap copy constructor is called\n";	
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor is called\n";
}


/* ############################################################
 * #						FUNCTIONALITY					  #
 * ############################################################ */

void ClapTrap::attack(const std::string &target)
{
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack\n";
		return;
	}

	--energy_points;

	std::cout << "ClapTrap " << name << " attacks "
			  << target << ", causing " << attack_damage
			  << " points of damage!\n";
}

/* I guess we take damage to ourselves.. */
void ClapTrap::takeDamage(unsigned amount)
{
	if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " is already dead\n";
		return;
	}

	if (amount >= hit_points)
		hit_points = 0;
	else
		hit_points -= amount;

	std::cout << "ClapTrap " << name << " takes "
			  << amount << " points of damage\n";
}

void ClapTrap::beRepaired(unsigned amount)
{
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " cannot be repaired\n";
		return;
	}

	--energy_points;

	unsigned restored = amount;

	if (restored > UINT_MAX - hit_points)
		restored = UINT_MAX - hit_points;

	hit_points += restored;

	std::cout << "ClapTrap " << name
			  << " repairs itself, restoring "
			  << restored << " hit points\n";
}

/* ############################################################
 * #						GETTERS							  #
 * ############################################################ */

unsigned ClapTrap::getHitPoints() const
{
	return hit_points;
}

unsigned ClapTrap::getEnergyPoints() const
{
	return energy_points;
}

unsigned ClapTrap::getAttackDamage() const
{
	return attack_damage;
}


/* ############################################################
 * #						SETTERS							  #
 * ############################################################ */

void ClapTrap::setHitPoints(unsigned itsHitPoints)
{
	hit_points = itsHitPoints;
}

void ClapTrap::setEnergyPoints(unsigned itsEnergyPoints)
{
	energy_points = itsEnergyPoints;
}

void ClapTrap::setAttackDamage(unsigned itsAttackDamage)
{
	attack_damage = itsAttackDamage;
}


/* ############################################################
 * #					OVERLOADED OPERATORS				  #
 * ############################################################ */

ClapTrap &ClapTrap::operator = (const ClapTrap &obj)
{
	std::cout << "Assignment operator is called\n";

	if (this == &obj)
		return *this;	

	name = obj.name;
	hit_points = obj.hit_points;
	energy_points = obj.energy_points;
	attack_damage = obj.attack_damage;

	return *this;
}
