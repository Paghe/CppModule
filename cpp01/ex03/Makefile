# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 20:03:37 by apaghera          #+#    #+#              #
#    Updated: 2023/07/15 11:47:10 by apaghera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = weapon
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror #-fsanitize=address 
SRC = main.cpp \
		HumanA.cpp \
		Weapon.cpp \
		HumanB.cpp \

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
