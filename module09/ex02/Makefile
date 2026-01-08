NAME = PmergeMe

CXX = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re