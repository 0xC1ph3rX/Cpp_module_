/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 03:01:51 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/18 06:44:10 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string Zombiename): _name(Zombiename){}
Zombie::~Zombie()
{
	std::cout << _name << " is destroyed" << std::endl;
}
void Zombie::announce(void){
	std::cout << _name << " BraiiiiiiinnnzzzZ... " << std::endl;
}

