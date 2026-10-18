#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap
{
public:
	/* Constructors & Destructors */
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &);
	virtual ~FragTrap();

	/* New methods */
	void highFivesGuys();

	/* Overloaded operators */
	FragTrap &operator = (const FragTrap &);
};

#endif
