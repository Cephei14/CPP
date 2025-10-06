NAME = harl

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Harl.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re fclean clean all