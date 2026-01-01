/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 09:40:56 by mtarza            #+#    #+#             */
/*   Updated: 2026/01/01 09:40:56 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("nameless")
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << CLR_GREEN << "[FragTrap] Default constructor for "
              << _name << CLR_RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << CLR_GREEN << "[FragTrap] Constructor for "
              << _name << CLR_RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << CLR_BLUE << "[FragTrap] Copy constructor cloning "
              << copy._name << CLR_RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << CLR_BLUE << "[FragTrap] Copy assignment syncing "
              << _name << " <= " << other._name << CLR_RESET << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << CLR_RED << "[FragTrap] Destructor shutting down "
              << _name << CLR_RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (!canAct("offer high fives"))
        return;
    std::cout << CLR_CYAN << "[FragTrap] " << _name
              << " requests a positive high five! (HP:" << _hitPoints
              << " | EN:" << _energyPoints << ")"
              << CLR_RESET << std::endl;
}

