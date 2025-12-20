# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 22:06:36 by mtarza            #+#    #+#              #
#    Updated: 2025/12/17 22:06:37 by mtarza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = megaphone
CXX     = g++
CXXFLAGS= -std=c++11 -Wall -Wextra -Werror
SRCS    = megaphone.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(NAME)

.PHONY: all clean
