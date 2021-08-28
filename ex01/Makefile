CC = clang++
NAME = phonebook
SRC =	Phonebook.cpp \
		Contact.cpp \
		main.cpp
HEADERS =	Phonebook.hpp \
			Contact.hpp
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(SRC) $(FLAGS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)