NAME = fixed

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : fclean clean all