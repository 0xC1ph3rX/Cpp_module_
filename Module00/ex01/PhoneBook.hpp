/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:06:52 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/17 22:06:53 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>


class PhoneBook {
private:
    Contact _contacts[8];
    int _contactCount;
    int _index;
    std::string formatField(std::string value);
    bool isNumber(std::string text);
    std::string takeInput(std::string label);
public:
    PhoneBook();
    void ft_addContact();
    void ft_displayContacts();
    void ft_displayContactDetails(int index);
    void ft_searchContact();
    ~PhoneBook();
};

#endif
