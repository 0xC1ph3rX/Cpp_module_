/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:04:39 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/03 19:04:41 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc == 2)
	{
		harl.complain(argv[1]);
		return 0;
	}

	std::cout << "Usage: ./harl <LEVEL>" << std::endl;
	std::cout << "Try one of: DEBUG, INFO, WARNING, ERROR" << std::endl;
	std::cout << std::endl;

	std::cout << "[DEBUG]" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "[INFO]" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "[WARNING]" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "[ERROR]" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "[UNKNOWN]" << std::endl;
	harl.complain("NOPE");

	return 0;
}
