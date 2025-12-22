/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:11:48 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/22 04:30:00 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// -----------------------------------------------------------------------------
// Constructors & Destructor
// -----------------------------------------------------------------------------

// Default Constructor
// Initializes the fixed point value to 0.
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Int Constructor
// Converts an integer to a fixed-point value.
// We shift 'n' to the left by 8 bits.
// Example: Fixed(1) -> 1 * 256 = 256 raw value.
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = n << _fractionalBits;
}

// Float Constructor
// Converts a float to a fixed-point value.
// 1. Multiply 'n' by 256 (1 << 8) to move decimals into integer part.
// 2. Use roundf() to convert to the nearest integer index.
// Example: Fixed(1.5f) -> 1.5 * 256 = 384 raw value.
Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

// Copy Constructor
// Creates a new Fixed object as a copy of 'other'.
// We use *this = other to reuse the assignment operator logic.
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy Assignment Operator
// Assigns the value of 'rhs' (Right Hand Side) to 'this' instance.
Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    
    // Self-assignment check: Don't do anything if we are assigning to ourself (a = a).
    if (this != &rhs) {
        // Copy the raw bits directly.
        this->_fixedPointValue = rhs.getRawBits();
    }
    // Return *this so we can chain assignments (a = b = c).
    return *this;
}

// Destructor
// Cleans up the object. Nothing special to free here since it's just an int.
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// -----------------------------------------------------------------------------
// Getters / Setters
// -----------------------------------------------------------------------------

// Returns the raw integer value stored in memory.
int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

// Sets the raw integer value manually.
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// -----------------------------------------------------------------------------
// Conversions
// -----------------------------------------------------------------------------

// toFloat
// Converts the fixed-point value back to a float.
// We cast raw value to float and divide by 256.0f (Reverse of constructor).
// Example: 384 / 256.0f = 1.5f.
float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

// toInt
// Converts the fixed-point value back to an integer.
// We shift right by 8 bits, effectively dividing by 256 and discarding decimals.
// Example: 384 >> 8 = 1. (Wait, 384 is 1.5, so 1 is truncated result).
int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// -----------------------------------------------------------------------------
// Operator Overload
// -----------------------------------------------------------------------------

// Stream Insertion Operator
// Allows us to use std::cout << fixedObject.
// It acts as a translator: "Print the float version of this object".
std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
}
