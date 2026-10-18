#include "ScavTrap.h"

#include <iostream>

/* Constructors & Destructors */
/* C++ prevents class from initializing
 * inherited member variables in the
 * member initializer list of a constructor!
 * learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes */
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor is called\n";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor is called\n";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap copy constructor is called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor is called\n";
}

/* Derived */
void ScavTrap::attack(const std::string &target)
{
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "ScavTrap " << name << " cannot attack\n";
		return;
	}

	--energy_points;

	std::cout << "ScavTrap " << name << " attacks "
			  << target << ", causing " << attack_damage
			  << " points of damage!\n";
}

/* New methods */
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode\n";
}

/* Overloaded operators */
ScavTrap &ScavTrap::operator = (const ScavTrap &obj)
{
	std::cout << "ScavTrap assignment operator called\n";

	if (this != &obj)
		ClapTrap::operator=(obj);

	return *this;
}
