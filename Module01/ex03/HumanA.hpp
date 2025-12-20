/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 23:22:40 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/18 23:23:13 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {
	std::string _name;
	Weapon &_weapon;

public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();
	void attack() const;
};

#endif
