NAME = Bureaucrat
SRC = main.cpp Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re