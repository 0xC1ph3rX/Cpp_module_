/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:22:36 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/18 09:22:47 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie {
	public:
		Zombie();
		~Zombie();
		void setNameZombie(std::string name);
		void announce(void);
	private:
		std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
