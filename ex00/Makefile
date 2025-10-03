NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)
%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re