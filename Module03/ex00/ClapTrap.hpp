/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 04:54:36 by mtarza            #+#    #+#             */
/*   Updated: 2026/01/01 04:59:48 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define CLR_RESET  "\033[0m"
#define CLR_RED    "\033[31m"
#define CLR_GREEN  "\033[32m"
#define CLR_YELLOW "\033[33m"
#define CLR_BLUE   "\033[34m"
#define CLR_MAG    "\033[35m"
#define CLR_CYAN   "\033[36m"

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

        bool canAct(const std::string &action) const;

    public:
        ClapTrap();                                 
        ClapTrap(const ClapTrap &copy);             
        ClapTrap &operator=(const ClapTrap &other); 
        ~ClapTrap();                  

        ClapTrap(std::string name);               

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
