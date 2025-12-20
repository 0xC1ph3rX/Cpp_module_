NAME = Zombie
CC = c++ 
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
CLEAN = rm -Rf
SRC = 	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp

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
	@printf "$(GREEN)The object file %s was successfully compiled.$(RST)\n" "$@"

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)
	@printf "$(GREEN)The app %s was successfully compiled.$(RST)\n" "$(NAME)"

clean:
	@$(CLEAN) $(OBJS)
	@printf "$(RED)Removing:$(RST) all objects files of %s app.\n" "$(NAME)"

fclean: clean
	@$(CLEAN) $(NAME)
	@printf "$(RED)Removing:$(RST) %s app.\n" "$(NAME)"
	@printf "$(RED)Cleaned up!$(RST)\n"

re: clean fclean all

.PHONY : all fclean re clean
