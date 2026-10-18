#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap
{
public:
	/* Constructors & Destructors */
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &);
	~ClapTrap();

	/* Functionality */
	void attack(const std::string &target);
	void takeDamage(unsigned amount);
	void beRepaired(unsigned amount);

	/* Getters */
	unsigned getHitPoints() const;
	unsigned getEnergyPoints() const;
	unsigned getAttackDamage() const;

	/* Setters */
	void setHitPoints(unsigned);
	void setEnergyPoints(unsigned);
	void setAttackDamage(unsigned);

	/* Overloaded operators */
	ClapTrap &operator = (const ClapTrap &);

private:
	std::string name;
	unsigned hit_points;
	unsigned energy_points;
	unsigned attack_damage;
};

#endif
