/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:06:01 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/19 19:06:06 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::_debug(void)
{
	std::cout
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void	Harl::_info(void)
{
	std::cout
		<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void	Harl::_warning(void)
{
	std::cout
		<< "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
		<< std::endl;
}

void	Harl::_error(void)
{
	std::cout
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*complaintFunctions[])(void) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};
	
	std::string	complaintLevels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == complaintLevels[i])
		{
			(this->*complaintFunctions[i])();
			break;
		}
	}
	return;

}
