NAME = Bureaucrat
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror #-fsanitize=address
SRC = main.cpp \
		Bureaucrat.cpp \

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all