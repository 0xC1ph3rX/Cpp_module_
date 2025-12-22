/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 03:09:18 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/22 03:09:23 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():number_value(0){
	std::cout << "Default constructor called" << std::endl;
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout <<"copy constructor called" << std::endl;
	 *this = copy;
}

Fixed& Fixed::operator=(Fixed const &rhy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->number_value = rhy.getRawBits();
	return *this;
}

int Fixed::getRawBits()const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->number_value;
}

void Fixed::setRawBits(int const raw)
{
	number_value = raw;
}
