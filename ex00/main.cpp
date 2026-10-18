#include "ClapTrap.h"

#include <iostream>

#include <cassert>

int main()
{
	ClapTrap robot("Biba");

	assert(robot.getHitPoints() == 10);
	assert(robot.getEnergyPoints() == 10);
	assert(robot.getAttackDamage() == 0);

	robot.attack("Boba");
	assert(robot.getEnergyPoints() == 9);

	robot.takeDamage(4);
	assert(robot.getHitPoints() == 6);

	robot.beRepaired(3);
	assert(robot.getHitPoints() == 9);
	assert(robot.getEnergyPoints() == 8);

	robot.takeDamage(100);
	assert(robot.getHitPoints() == 0);

	robot.beRepaired(5);
	assert(robot.getHitPoints() == 0);


	ClapTrap robot2("Pepa");
	robot2.setEnergyPoints(3);

	robot = robot2;
	assert(robot.getEnergyPoints() == 3);


	ClapTrap copy(robot2);
	
	assert(copy.getHitPoints() == robot2.getHitPoints());
	assert(copy.getEnergyPoints() == robot2.getEnergyPoints());
	assert(copy.getAttackDamage() == robot2.getAttackDamage());

	return 0;
}
