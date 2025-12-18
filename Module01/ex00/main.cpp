/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 06:32:56 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/18 06:59:52 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie func_1("Stack Zombie : ");
	func_1.announce();
	Zombie *func_2 = newZombie("Heap Zombie : ");
	func_2->announce();
	randomChump("any Random Zombie : ");
	delete func_2;
	return 0;
}
