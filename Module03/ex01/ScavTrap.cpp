/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 09:45:06 by mtarza            #+#    #+#             */
/*   Updated: 2026/01/01 09:45:06 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("nameless")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << CLR_GREEN << "[ScavTrap] Default constructor for "
              << _name << CLR_RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;

    std::cout << CLR_GREEN << "[ScavTrap] Constructor for "
              << _name << CLR_RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << CLR_BLUE << "[ScavTrap] Copy constructor cloning "
              << copy._name << CLR_RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << CLR_BLUE << "[ScavTrap] Copy assignment syncing "
              << _name << " <= " << other._name << CLR_RESET << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << CLR_RED << "[ScavTrap] Destructor shutting down "
              << _name << CLR_RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (!canAct("attack as ScavTrap"))
        return;
    _energyPoints--;
    std::cout << CLR_MAG << "[ScavTrap] " << _name << " lunges at " << target 
              << " causing " << _attackDamage << " damage! (HP:" << _hitPoints
              << " | EN:" << _energyPoints << ")"
              << CLR_RESET << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << CLR_CYAN << "[ScavTrap] " << _name
              << " is now in Gate Keeper mode." << CLR_RESET << std::endl;
}
