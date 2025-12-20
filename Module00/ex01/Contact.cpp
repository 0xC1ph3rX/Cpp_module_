/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:06:30 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/17 22:06:31 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

void Contact::ft_setFirstName(std::string v) {
    _firstName = v;
}

void Contact::ft_setLastName(std::string v) {
    _lastName = v;
}

void Contact::ft_setNickname(std::string v) {
    _nickname = v;
}

void Contact::ft_setPhoneNumber(std::string v) {
    _phoneNumber = v;
}

void Contact::ft_setDarkestSecret(std::string v) {
    _darkestSecret = v;
}

std::string Contact::ft_getFirstName() {
    return _firstName;
}

std::string Contact::ft_getLastName() {
    return _lastName;
}

std::string Contact::ft_getNickname() {
    return _nickname;
}

std::string Contact::ft_getPhoneNumber() {
    return _phoneNumber;
}

std::string Contact::ft_getDarkestSecret() {
    return _darkestSecret;
}

Contact::~Contact() {}
