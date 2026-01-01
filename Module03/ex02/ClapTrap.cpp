/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 06:37:54 by mtarza            #+#    #+#             */
/*   Updated: 2026/01/01 06:37:54 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("nameless"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << CLR_GREEN << "[ClapTrap] Default constructor spun up for "
              << _name << CLR_RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << CLR_GREEN << "[ClapTrap] Constructor spun up for "
              << _name << CLR_RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
    : _name(copy._name), _hitPoints(copy._hitPoints),
      _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
    std::cout << CLR_BLUE << "[ClapTrap] Copy constructor cloning "
              << copy._name << CLR_RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << CLR_BLUE << "[ClapTrap] Copy assignment syncing "
              << _name << " <= " << other._name << CLR_RESET << std::endl;
    if (this != &other) 
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << CLR_RED << "[ClapTrap] Destructor shutting down "
              << _name << CLR_RESET << std::endl;
}

bool ClapTrap::canAct(const std::string &action) const
{
    if (_hitPoints == 0)
    {
        std::cout << CLR_RED << "[ClapTrap] " << _name
                  << " cannot " << action << ": out of hit points."
                  << CLR_RESET << std::endl;
        return false;
    }
    if (_energyPoints == 0)
    {
        std::cout << CLR_YELLOW << "[ClapTrap] " << _name
                  << " cannot " << action << ": no energy left."
                  << CLR_RESET << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::attack(const std::string& target)
{
    if (!canAct("attack"))
        return;
    _energyPoints--;
    std::cout << CLR_MAG << "[ClapTrap] " << _name << " attacks "
              << target << ", causing " << _attackDamage
              << " points of damage! (HP:" << _hitPoints
              << " | EN:" << _energyPoints << ")"
              << CLR_RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << CLR_RED << "[ClapTrap] " << _name
                  << " is already down; extra damage has no effect."
                  << CLR_RESET << std::endl;
        return;
    }
    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;

    std::cout << CLR_RED << "[ClapTrap] " << _name << " took "
              << amount << " damage! (HP:" << _hitPoints
              << " | EN:" << _energyPoints << ")"
              << CLR_RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!canAct("repair"))
        return;
    _energyPoints--;
    _hitPoints += amount;
    std::cout << CLR_CYAN << "[ClapTrap] " << _name
              << " repairs itself, recovering " << amount << " HP!"
              << " (HP:" << _hitPoints << " | EN:" << _energyPoints << ")"
              << CLR_RESET << std::endl;
}
