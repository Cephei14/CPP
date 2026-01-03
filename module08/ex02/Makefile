NAME = MutantStack

CXX = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ) *.txt

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re