# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 22:42:41 by apaghera          #+#    #+#              #
#    Updated: 2023/07/10 12:53:11 by apaghera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = phoneBook
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = Contact.cpp \
		PhoneBook.cpp \
		main.cpp \
		Search.cpp \

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
