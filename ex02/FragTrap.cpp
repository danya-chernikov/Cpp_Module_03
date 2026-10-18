#include "FragTrap.h"

#include <iostream>

/* Constructors & Destructors */
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor is called\n";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor is called\n";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap copy constructor is called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor is called\n";
}

/* New methods */
void FragTrap::highFivesGuys()
{
	std::cout << "A positive high-fives request\n";
}

/* Overloaded operators */
FragTrap &FragTrap::operator = (const FragTrap &obj)
{
	std::cout << "FragTrap assignment operator is called\n";

	if (this != &obj)
		ClapTrap::operator=(obj);

	return *this;
}
