/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 06:33:02 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/18 06:46:35 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie {
	public:
		Zombie(std::string name);
		~Zombie();
	void announce(void);
	private:
		std::string _name;
};

Zombie* newZombie( std::string Name );
void randomChump( std::string name );

#endif
