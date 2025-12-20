/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:01:14 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/18 23:22:54 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class Weapon {

	std::string type;

public:
	Weapon(const std::string &type);
	const std::string &getType() const;
	void setType(const std::string &type);
};
#endif
