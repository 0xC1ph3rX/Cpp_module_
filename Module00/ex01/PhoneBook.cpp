/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:06:50 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/17 22:06:51 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


static const std::string CLR_RESET = "\033[0m";
static const std::string CLR_INFO = "\033[36m";
static const std::string CLR_WARN = "\033[33m";
static const std::string CLR_HIGHLIGHT = "\033[35m";

std::string PhoneBook::formatField(std::string value)
{
    if (value.length() > 10)
        return value.substr(0, 9) + ".";
    return value;
}

bool PhoneBook::isNumber(std::string text)
{
    if (text.empty())
        return false;
    for (size_t i = 0; i < text.length(); i++)
    {
        if (!std::isdigit(text[i]))
            return false;
    }
    return true;
}

std::string PhoneBook::takeInput(std::string label)
{
    std::string input;
    while (true)
    {
        std::cout << CLR_INFO << label << CLR_RESET;
        if (!std::getline(std::cin, input))
            return "";
        if (!input.empty())
            return input;
        std::cout << CLR_WARN << "This field cannot be empty." << CLR_RESET << std::endl;
    }
}

PhoneBook::PhoneBook()
{
    _contactCount = 0;
    _index = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::ft_addContact()
{
    if (_index >= 8)
        _index = 0;

    std::string name;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    name = takeInput("Enter First Name: ");
    if (!std::cin)
        return;
    lastName = takeInput("Enter Last Name: ");
    if (!std::cin)
        return;
    nickname = takeInput("Enter Nickname: ");
    if (!std::cin)
        return;
    phoneNumber = takeInput("Enter Phone Number: ");
    if (!std::cin)
        return;
    darkestSecret = takeInput("Enter Darkest Secret: ");
    if (!std::cin)
        return;

    _contacts[_index].ft_setFirstName(name);
    _contacts[_index].ft_setLastName(lastName);
    _contacts[_index].ft_setNickname(nickname);
    _contacts[_index].ft_setPhoneNumber(phoneNumber);
    _contacts[_index].ft_setDarkestSecret(darkestSecret);

    _index = (_index + 1) % 8;
    if (_contactCount < 8)
        _contactCount++;
}

void PhoneBook::ft_displayContacts()
{
    if (_contactCount == 0)
    {
        std::cout << CLR_WARN << "No contacts available." << CLR_RESET << std::endl;
        return;
    }

    std::cout << CLR_HIGHLIGHT
              << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << CLR_RESET << std::endl;

    for (int i = 0; i < _contactCount; i++)
    {
        Contact contact = _contacts[i];
        std::cout << std::setw(10) << (i + 1) << "|"
                  << std::setw(10) << formatField(contact.ft_getFirstName()) << "|"
                  << std::setw(10) << formatField(contact.ft_getLastName()) << "|"
                  << std::setw(10) << formatField(contact.ft_getNickname()) << std::endl;
    }
}

void PhoneBook::ft_displayContactDetails(int index)
{
    if (index < 0 || index >= _contactCount)
    {
        std::cout << CLR_WARN << "Invalid index." << CLR_RESET << std::endl;
        return;
    }

    Contact contact = _contacts[index];
    std::cout << CLR_HIGHLIGHT << "First Name: " << CLR_RESET << contact.ft_getFirstName() << std::endl;
    std::cout << CLR_HIGHLIGHT << "Last Name: " << CLR_RESET << contact.ft_getLastName() << std::endl;
    std::cout << CLR_HIGHLIGHT << "Nickname: " << CLR_RESET << contact.ft_getNickname() << std::endl;
    std::cout << CLR_HIGHLIGHT << "Phone Number: " << CLR_RESET << contact.ft_getPhoneNumber() << std::endl;
    std::cout << CLR_HIGHLIGHT << "Darkest Secret: " << CLR_RESET << contact.ft_getDarkestSecret() << std::endl;
}

void PhoneBook::ft_searchContact()
{
    if (_contactCount == 0)
    {
        std::cout << CLR_WARN << "No contacts available." << CLR_RESET << std::endl;
        return;
    }

    ft_displayContacts();
    std::string input;
    std::cout << CLR_INFO << "Enter index to display: " << CLR_RESET;
    if (!std::getline(std::cin, input))
        return;
    if (!isNumber(input))
    {
        std::cout << CLR_WARN << "Invalid index." << CLR_RESET << std::endl;
        return;
    }

    int idx = std::atoi(input.c_str()) - 1;
    if (idx < 0 || idx >= _contactCount)
    {
        std::cout << CLR_WARN << "Invalid index." << CLR_RESET << std::endl;
        return;
    }
    ft_displayContactDetails(idx);
}
