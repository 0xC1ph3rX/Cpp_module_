/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:06:43 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/17 22:09:45 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


static const std::string CLR_RESET = "\033[0m";
static const std::string CLR_PROMPT = "\033[32m";
static const std::string CLR_WARN = "\033[33m";

int main() {
    PhoneBook phonebook;
    std::string command;
    while (true)
    {
        std::cout << CLR_PROMPT << "Enter a command (ADD, SEARCH , EXIT): " << CLR_RESET;
        if (!std::getline(std::cin, command)) {
            std::cout << CLR_WARN << "\nInput ended. Exiting." << CLR_RESET << std::endl;
            break;
        }
        if (!command.compare("ADD")) {
            phonebook.ft_addContact();
            if (!std::cin) {
                std::cout << CLR_WARN << "\nInput ended. Exiting." << CLR_RESET << std::endl;
                break;
            }
        } else if (!command.compare("SEARCH")) {
            phonebook.ft_searchContact();
            if (!std::cin) {
                std::cout << CLR_WARN << "\nInput ended. Exiting." << CLR_RESET << std::endl;
                break;
            }
        } else if (!command.compare("EXIT"))
            break;
        else
            std::cout << CLR_WARN << "Invalid command. Please try again." << CLR_RESET << std::endl;
    }
    return (0);
}
