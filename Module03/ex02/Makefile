# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/01 09:40:51 by mtarza            #+#    #+#              #
#    Updated: 2026/01/01 09:40:51 by mtarza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := repetitive_work

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
