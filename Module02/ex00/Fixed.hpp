/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:11:48 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/22 04:25:00 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// Orthodox Canonical Form (OCF) Requirements:
// 1. Default Constructor
// 2. Copy Constructor
// 3. Copy Assignment Operator
// 4. Destructor

class Fixed {
private:
    int                 _fixedPointValue; // The raw integer that stores our value
    static const int    _fractionalBits = 8; // Always 8 for this module

public:
    // 1. Default Constructor: Initializes _fixedPointValue to 0
    Fixed();

    // 2. Copy Constructor: Initializes a new object as a copy of another
    Fixed(const Fixed &other);

    // 3. Copy Assignment Operator: Assigns one existing object to another
    Fixed &operator=(const Fixed &rhs);

    // 4. Destructor: Cleans up (not much to do for int, but required)
    ~Fixed();

    // Getter: Returns the raw value stored in memory
    int getRawBits(void) const;

    // Setter: Manually sets the raw value
    void setRawBits(int const raw);
};

#endif
