#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
public:
	/* Constructors & Destructors */
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &);
	virtual ~ScavTrap();

	/* Derived */
	virtual void attack(const std::string &target);

	/* New methods */
	void guardGate();

	/* Overloaded operators */
	ScavTrap &operator = (const ScavTrap &);
};

#endif
