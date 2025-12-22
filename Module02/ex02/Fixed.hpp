/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:11:48 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/22 04:35:00 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    // OCF
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &rhs);
    ~Fixed();

    // Accessors
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Conversions
    float toFloat(void) const;
    int toInt(void) const;

    // -------------------------------------------------------------------------
    // NEW IN EX02: Operator Overloading
    // -------------------------------------------------------------------------

    // 1. Comparison Operators
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;

    // 2. Arithmetic Operators
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    // 3. Increment / Decrement Operators
    // Pre-increment: ++a
    Fixed &operator++(); 
    // Post-increment: a++ (int argument is a dummy flag)
    Fixed operator++(int);
    // Pre-decrement: --a
    Fixed &operator--();
    // Post-decrement: a--
    Fixed operator--(int);

    // 4. Static Min/Max
    // Non-const version (returns reference to smallest/largest)
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    // Const version
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
