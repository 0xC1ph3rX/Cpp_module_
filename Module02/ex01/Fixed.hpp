/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:11:48 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/22 04:30:00 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // Required for roundf

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &rhs);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    // -------------------------------------------------------------------------
    // NEW IN EX01
    // -------------------------------------------------------------------------

    // Constructor taking an integer: Converts it to fixed point
    // Example: Fixed(1) -> stores 256
    Fixed(const int n);

    // Constructor taking a float: Converts it to fixed point
    // Example: Fixed(1.5f) -> stores 384
    Fixed(const float n);

    // Converts back to float
    // Example: 384 -> returns 1.5f
    float toFloat(void) const;

    // Converts back to integer
    // Example: 384 -> returns 1 (truncates or rounds? Subject implies standard cast behavior usually, but implementation varies. We will use roundf or shift.)
    int toInt(void) const;
};

// Stream insertion operator overload
// Allows: std::cout << a << std::endl;
// Should print the floating point representation.
std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
