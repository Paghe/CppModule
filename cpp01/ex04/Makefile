# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 11:57:49 by apaghera          #+#    #+#              #
#    Updated: 2023/07/15 11:58:26 by apaghera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex04
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror #-fsanitize=address 
SRC = main.cpp \
		File.cpp \

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
