#include "FragTrap.h"

#include <iostream>
#include <sstream>
#include <string>

#include <cassert>
#include <climits>

void test_initial_values_and_combat()
{
    FragTrap def;
    assert(def.getHitPoints() == 100);
    assert(def.getEnergyPoints() == 100);
    assert(def.getAttackDamage() == 30);

    FragTrap robot("Biba");
    robot.attack("Boba");
    assert(robot.getEnergyPoints() == 99);
    robot.takeDamage(40);
    assert(robot.getHitPoints() == 60);
    robot.beRepaired(15);
    assert(robot.getHitPoints() == 75);
    assert(robot.getEnergyPoints() == 98);

    robot.takeDamage(1000);
    assert(robot.getHitPoints() == 0);
    robot.attack("Boba");
    robot.beRepaired(10);
    assert(robot.getHitPoints() == 0);
    assert(robot.getEnergyPoints() == 98);
}

void test_energy_and_limits()
{
    FragTrap robot("Pepa");
    for (int i = 0; i < 100; ++i)
        robot.attack("Yura");
    assert(robot.getEnergyPoints() == 0);

    robot.attack("Yura");
    assert(robot.getEnergyPoints() == 0);

    robot.takeDamage(20); // Damage is received even with no energy
    assert(robot.getHitPoints() == 80);

    robot.beRepaired(10);
    assert(robot.getHitPoints() == 80);

    FragTrap max_hp("Overflow");
    max_hp.setHitPoints(UINT_MAX - 5U);
    max_hp.beRepaired(20);
    assert(max_hp.getHitPoints() == UINT_MAX);
    assert(max_hp.getEnergyPoints() == 99);
}

void test_canonical_form()
{
    FragTrap original("Original");
    original.takeDamage(25);
    original.setEnergyPoints(7);
    original.setAttackDamage(99);

    FragTrap copy(original);
    assert(copy.getHitPoints() == 75);
    assert(copy.getEnergyPoints() == 7);
    assert(copy.getAttackDamage() == 99);

    FragTrap assigned("Assigned");
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
    FragTrap frag("Poly");
    ClapTrap *base = &frag;

    std::ostringstream captured;
    std::streambuf *previous = std::cout.rdbuf(captured.rdbuf());

    base->attack("Enemy");
    frag.highFivesGuys();

    std::cout.rdbuf(previous);

    assert(frag.getEnergyPoints() == 99);
    assert(captured.str().find("ClapTrap Poly attacks Enemy") != std::string::npos);
    assert(captured.str().find("A positive high-fives request") != std::string::npos);

    captured.str("");
    captured.clear();

    previous = std::cout.rdbuf(captured.rdbuf());

    ClapTrap *dynamic = new FragTrap("Dynamic");
    delete dynamic;

    std::cout.rdbuf(previous);

    std::string log = captured.str();

    std::string::size_type derived = log.find("FragTrap destructor is called");
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

    std::cout << "ALL FRAGTRAP TESTS PASSED\n";

    return 0;
}
