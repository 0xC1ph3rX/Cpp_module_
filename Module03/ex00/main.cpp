/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 06:51:47 by mtarza            #+#    #+#             */
/*   Updated: 2026/01/01 06:51:48 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << CLR_CYAN << "=== ClapTrap: Aaaaand... OPEN! ===" << CLR_RESET << std::endl;

    std::cout << CLR_YELLOW << "\n-- Construct & copy --" << CLR_RESET << std::endl;
    ClapTrap alpha("Alpha");
    ClapTrap beta("Beta");
    ClapTrap gamma(alpha); // copy constructor
    ClapTrap delta;
    delta = beta;          // assignment

    std::cout << CLR_YELLOW << "\n-- Attack until energy dries up --" << CLR_RESET << std::endl;
    for (int i = 0; i < 11; ++i)
        alpha.attack("training dummy");

    std::cout << CLR_YELLOW << "\n-- Damage and repair cycles --" << CLR_RESET << std::endl;
    alpha.takeDamage(4);
    alpha.beRepaired(3);
    alpha.takeDamage(20);      // drops to 0 HP
    alpha.attack("Ghost");     // should fail: 0 HP
    alpha.beRepaired(5);       // should fail: 0 HP

    std::cout << CLR_YELLOW << "\n-- Independent ClapTrap run --" << CLR_RESET << std::endl;
    ClapTrap healer("Healer");
    healer.takeDamage(8);
    healer.beRepaired(5);

    std::cout << CLR_GREEN << "\n(Destruction chain on exit)" << CLR_RESET << std::endl;
    return 0;
}
