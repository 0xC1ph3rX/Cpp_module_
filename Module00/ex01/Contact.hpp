/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:19:53 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/17 22:19:54 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
 
public:
    Contact();
    void ft_setFirstName(std::string v);
    void ft_setLastName(std::string v);
    void ft_setNickname(std::string v);
    void ft_setPhoneNumber(std::string v);
    void ft_setDarkestSecret(std::string v);

    std::string ft_getFirstName();
    std::string ft_getLastName();
    std::string ft_getNickname();
    std::string ft_getPhoneNumber();
    std::string ft_getDarkestSecret();
    ~Contact();
};

#endif
