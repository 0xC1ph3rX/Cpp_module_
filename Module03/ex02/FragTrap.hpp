/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 09:40:55 by mtarza            #+#    #+#             */
/*   Updated: 2026/01/01 09:40:55 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const FragTrap &copy);
        FragTrap &operator=(const FragTrap &other);
        FragTrap(std::string name);
        ~FragTrap();

        void highFivesGuys(void);
};

#endif
