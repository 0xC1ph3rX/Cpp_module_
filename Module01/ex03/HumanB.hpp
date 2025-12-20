/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 23:22:45 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/18 23:23:10 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
	std::string _name;
	Weapon *_weapon;

public:
	HumanB(const std::string name);
	~HumanB();
	void setWeapon(Weapon &weapon);
	void attack() const;
};

#endif
