/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 23:22:50 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/18 23:23:02 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
	this->type = type;
}

const std::string &Weapon::getType() const
{
	return(this->type);
}

void Weapon::setType(const std::string &type)
{
	this->type = type;
}
