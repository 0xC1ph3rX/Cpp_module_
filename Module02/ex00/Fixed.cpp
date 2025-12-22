/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:11:48 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/22 04:25:00 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default Constructor
// Called when you do: Fixed a;
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy Constructor
// Called when you do: Fixed b(a);
// "Create me a new Fixed 'b', and make it look exactly like 'a'"
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    // We can use the assignment operator, or just copy the bits directly.
    // The subject often wants us to show specific logic.
    // Ideally: *this = other;
    // But for raw bits:
    this->_fixedPointValue = other.getRawBits();
}

// Copy Assignment Operator
// Called when you do: b = a; (both already exist)
// "Update 'b' to look like 'a'"
Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;

    // Self-assignment check: if (a = a), do nothing.
    if (this != &rhs) {
        this->_fixedPointValue = rhs.getRawBits();
    }
    // Return *this to allow chaining: a = b = c;
    return *this;
}

// Destructor
// Called when the object goes out of scope (end of function or block)
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Returns the raw integer value
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

// Sets the raw integer value directly
void Fixed::setRawBits(int const raw) {
    // Note: The subject doesn't ask for a cout here usually, but it helps debugging
    // std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}
