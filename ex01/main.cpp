#include "ScavTrap.h"

#include <iostream>
#include <sstream>
#include <string>

#include <cassert>
#include <climits>

void test_initial_values_and_combat()
{
	ScavTrap def;
	assert(def.getHitPoints() == 100);
	assert(def.getEnergyPoints() == 50);
	assert(def.getAttackDamage() == 20);

	ScavTrap robot("Biba");
	robot.attack("Boba");
	assert(robot.getEnergyPoints() == 49);
	robot.takeDamage(40);
	assert(robot.getHitPoints() == 60);
	robot.beRepaired(15);
	assert(robot.getHitPoints() == 75);
	assert(robot.getEnergyPoints() == 48);

	robot.takeDamage(1000);
	assert(robot.getHitPoints() == 0);
	robot.attack("Boba");
	robot.beRepaired(10);
	assert(robot.getHitPoints() == 0);
	assert(robot.getEnergyPoints() == 48);
}

void test_energy_and_limits()
{
	ScavTrap robot("Pepa");
	for (int i = 0; i < 50; ++i)
		robot.attack("Yura");
	assert(robot.getEnergyPoints() == 0);
	robot.attack("Yura");
	assert(robot.getEnergyPoints() == 0);
	robot.takeDamage(20); // Even with no energy, damage is received
	assert(robot.getHitPoints() == 80);
	robot.beRepaired(10);
	assert(robot.getHitPoints() == 80);

	ScavTrap max_hp("Overflow");	
	max_hp.setHitPoints(UINT_MAX - 5U);
	max_hp.beRepaired(20);
	assert(max_hp.getHitPoints() == UINT_MAX);
	assert(max_hp.getEnergyPoints() == 49);
}

void test_canonical_form()
{
	ScavTrap original("Original");
	original.takeDamage(25);
	original.setEnergyPoints(7);
	original.setAttackDamage(99);

	ScavTrap copy(original);
	assert(copy.getHitPoints() == 75);
	assert(copy.getEnergyPoints() == 7);
	assert(copy.getAttackDamage() == 99);

	ScavTrap assigned("Assigned");
	assigned = original;
	assert(assigned.getHitPoints() == 75);
	assert(assigned.getEnergyPoints() == 7);
	assert(assigned.getAttackDamage() == 99);
	assigned = assigned;
	assert(assigned.getHitPoints() == 75);
	assert(assigned.getEnergyPoints() == 7);
	assert(assigned.getAttackDamage() == 99);

	copy.takeDamage(10);
	assert(copy.getHitPoints() == 65);
	assert(original.getHitPoints() == 75);
}

void test_polymorphism_and_destruction()
{
	ScavTrap scav("Poly");
	ClapTrap *base = &scav;

	std::ostringstream captured;
	std::streambuf *previous = std::cout.rdbuf(captured.rdbuf());
	base->attack("Enemy");
	scav.guardGate();
	std::cout.rdbuf(previous);

	assert(scav.getEnergyPoints() == 49);
	assert(captured.str().find("ScavTrap Poly attacks Enemy") != std::string::npos);
	assert(captured.str().find("Gate keeper mode") != std::string::npos);

	captured.str("");
	captured.clear();
	previous = std::cout.rdbuf(captured.rdbuf());
	ClapTrap *dynamic = new ScavTrap("Dynamic");
	delete dynamic;
	std::cout.rdbuf(previous);

	std::string log = captured.str();
	std::string::size_type derived = log.find("ScavTrap destructor is called");
	std::string::size_type parent = log.find("ClapTrap destructor is called");
	assert(derived != std::string::npos);
	assert(parent != std::string::npos);
	assert(derived < parent);
}

int main()
{
	test_initial_values_and_combat();
	std::cout << "\n########################################\n";

	test_energy_and_limits();
	std::cout << "\n########################################\n";

	test_canonical_form();
	std::cout << "\n########################################\n";

	test_polymorphism_and_destruction();

	std::cout << "ALL SCAVTRAP TESTS PASSED\n";

	return 0;
}
