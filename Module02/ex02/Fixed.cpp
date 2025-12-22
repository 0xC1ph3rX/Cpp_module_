/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:11:48 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/22 04:35:00 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// -----------------------------------------------------------------------------
// Constructors & Destructor (Logs removed typically for Ex02 clean output)
// -----------------------------------------------------------------------------

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int n) {
    this->_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float n) {
    this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

// -----------------------------------------------------------------------------
// Accessors & Conversions
// -----------------------------------------------------------------------------

int Fixed::getRawBits(void) const { return this->_fixedPointValue; }
void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }
float Fixed::toFloat(void) const { return (float)this->_fixedPointValue / (float)(1 << _fractionalBits); }
int Fixed::toInt(void) const { return this->_fixedPointValue >> _fractionalBits; }

// -----------------------------------------------------------------------------
// Comparison Operators
// -----------------------------------------------------------------------------

bool Fixed::operator>(const Fixed &rhs) const { return this->_fixedPointValue > rhs.getRawBits(); }
bool Fixed::operator<(const Fixed &rhs) const { return this->_fixedPointValue < rhs.getRawBits(); }
bool Fixed::operator>=(const Fixed &rhs) const { return this->_fixedPointValue >= rhs.getRawBits(); }
bool Fixed::operator<=(const Fixed &rhs) const { return this->_fixedPointValue <= rhs.getRawBits(); }
bool Fixed::operator==(const Fixed &rhs) const { return this->_fixedPointValue == rhs.getRawBits(); }
bool Fixed::operator!=(const Fixed &rhs) const { return this->_fixedPointValue != rhs.getRawBits(); }

// -----------------------------------------------------------------------------
// Arithmetic Operators
// -----------------------------------------------------------------------------

Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue + rhs.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue - rhs.getRawBits());
    return result;
}

// MULTIPLICATION
// Use long long to prevent overflow before shifting back
Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed result;
    long long temp = (long long)this->_fixedPointValue * (long long)rhs.getRawBits();
    // Divide by 256 once because: (A*256) * (B*256) = (A*B)*65536. We want (A*B)*256.
    result.setRawBits(temp >> _fractionalBits);
    return result;
}

// DIVISION
// Bit hack: Shift numerator LEFT first to maintain precision, then divide
Fixed Fixed::operator/(const Fixed &rhs) const {
    Fixed result;
    if (rhs.getRawBits() == 0) {
        // Handle division by zero? Subject doesn't specify, but safer not to crash silently.
        // For 42, usually undefined behavior is acceptable or print error.
        // We'll proceed with standard int logic (crash or inf) or just return 0.
        // Let's rely on standard logic (crash) or careful check.
        // Simplest: just don't handle it (it's user responsibility) or return 0.
        // But the "hack" is: (A*256 / B*256) = A/B (int). Precision lost.
        // Better: ((A*256)*256) / (B*256) = (A/B)*256.
        long long temp = (long long)this->_fixedPointValue << _fractionalBits;
        if (rhs.getRawBits() != 0)
            result.setRawBits(temp / rhs.getRawBits());
    } else {
        long long temp = (long long)this->_fixedPointValue << _fractionalBits;
        result.setRawBits(temp / rhs.getRawBits()); 
    }
    return result;
}

// -----------------------------------------------------------------------------
// Increment / Decrement
// -----------------------------------------------------------------------------

// Pre-increment (++a)
Fixed &Fixed::operator++() {
    this->_fixedPointValue++; // Add 1 raw unit (Epsilon)
    return *this;
}

// Post-increment (a++)
Fixed Fixed::operator++(int) {
    Fixed temp(*this); // Make a copy of old value
    this->_fixedPointValue++; // Increment actual
    return temp; // Return old value
}

// Pre-decrement (--a)
Fixed &Fixed::operator--() {
    this->_fixedPointValue--;
    return *this;
}

// Post-decrement (a--)
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

// -----------------------------------------------------------------------------
// Min / Max
// -----------------------------------------------------------------------------

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
}
