/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:54:31 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/18 09:22:53 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 42;
	Zombie *zombie = zombieHorde(N,"zombiee");

	for(int a = 0; a < N ; a++) zombie[a].announce();
	delete [] zombie;
}
