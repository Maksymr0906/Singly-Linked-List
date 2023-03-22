NAME = debug

SRC =   main.cpp List.cpp Book.cpp

SRCDIR = source/

OBJDIR = objects/


OBJ = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ) 
	g++ $(OBJ) -o $(NAME) $(FLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	g++ -std=c++17 $(FLAGS) -I ./header -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all