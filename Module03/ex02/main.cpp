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
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << CLR_CYAN << "=== Repetitive work: Scav vs Frag ===" << CLR_RESET << std::endl;

    std::cout << CLR_YELLOW << "\n-- Build roster --" << CLR_RESET << std::endl;
    ScavTrap gatekeeper("GateKeeper");
    FragTrap heavy("Heavy");
    FragTrap cloneHeavy(heavy);
    ScavTrap assignTarget;
    assignTarget = gatekeeper;

    std::cout << CLR_YELLOW << "\n-- ScavTrap abilities --" << CLR_RESET << std::endl;
    gatekeeper.guardGate();
    gatekeeper.attack("trespasser");
    gatekeeper.takeDamage(60);
    gatekeeper.beRepaired(25);

    std::cout << CLR_YELLOW << "\n-- FragTrap abilities --" << CLR_RESET << std::endl;
    heavy.attack("dummy");
    heavy.highFivesGuys();
    heavy.takeDamage(40);
    heavy.beRepaired(15);
    heavy.highFivesGuys();

    std::cout << CLR_YELLOW << "\n-- Exhaust FragTrap energy to show guard rails --" << CLR_RESET << std::endl;
    for (int i = 0; i < 105; ++i)
        heavy.attack("energy sink");

    std::cout << CLR_GREEN << "\n(Destruction chain on exit)" << CLR_RESET << std::endl;
    return 0;
}
