# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 22:50:35 by mtarza            #+#    #+#              #
#    Updated: 2025/12/18 23:23:08 by mtarza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Violence
CC = c++ 
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
CLEAN = rm -Rf
SRC = 	main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp

OBJS := $(SRC:.cpp=.o)


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

all: $(NAME)

%.o:%.cpp
	@$(CC) -c $(CPPFLAGS) $< -o $@
	@echo "$(GREEN)The object file $@ was successfully compiled. $(RST)"

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)
	@echo "$(GREEN)The app $(NAME) was successfully compiled. $(RST)"

clean:
	@$(CLEAN) $(OBJS)
	@echo "$(RED)Removing:$(RST) all objects files of $(NAME) app."

fclean: clean
	@$(CLEAN) $(NAME)
	@echo "$(RED)Removing:$(RST) $(NAME) app."
	@echo "$(RED)Cleaned up!$(RST)"

re: clean fclean all

.PHONY : all fclean re clean
