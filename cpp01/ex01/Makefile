# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 16:12:30 by apaghera          #+#    #+#              #
#    Updated: 2023/07/11 16:23:53 by apaghera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror #-fsanitize=address 
SRC = main.cpp \
		Zombie.cpp \
		zombieHorde.cpp \

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
