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

int main()
{
    std::cout << CLR_CYAN << "=== Serena, my love! ===" << CLR_RESET << std::endl;
    std::cout << CLR_YELLOW << "\n-- Construction chain --" << CLR_RESET << std::endl;
    ScavTrap serena("Serena");
    ScavTrap watcher("Watcher");
    ScavTrap copySerena(serena);
    watcher = serena;

    std::cout << CLR_YELLOW << "\n-- ScavTrap offense/defense --" << CLR_RESET << std::endl;
    serena.attack("intruder");
    serena.takeDamage(30);
    serena.beRepaired(15);

    std::cout << CLR_YELLOW << "\n-- Gate keeping mode --" << CLR_RESET << std::endl;
    serena.guardGate();
    serena.guardGate();

    std::cout << CLR_YELLOW << "\n-- Resource exhaustion --" << CLR_RESET << std::endl;
    for (int i = 0; i < 55; ++i)
        serena.attack("endless dummy");

    std::cout << CLR_GREEN << "\n(Destruction chain on exit)" << CLR_RESET << std::endl;
    return 0;
}
