/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 03:07:41 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/22 03:08:07 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int number_value;
		static const int bits = 8;
	public:

	Fixed();
	Fixed(const Fixed &copy);
	Fixed& operator=(Fixed const &ryh);
	~Fixed();

	int getRawBits(void)const;
	void setRawBits(int const raw);
};

#endif
