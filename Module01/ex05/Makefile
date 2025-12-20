# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 19:04:57 by mtarza            #+#    #+#              #
#    Updated: 2025/12/19 19:04:58 by mtarza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := harl

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RST		:= \033[0m

SRCS := main.cpp Harl.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Built$(RST) $(CYAN)$(NAME)$(RST)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiled$(RST) $@"

clean:
	@rm -f $(OBJS)
	@echo "$(RED)Removed$(RST) objects"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed$(RST) $(CYAN)$(NAME)$(RST)"

re: fclean all

.PHONY: all clean fclean re
