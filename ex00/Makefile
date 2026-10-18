CXX=c++

NAME=clap_trap

CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -O0 -g3

all: $(NAME)

$(NAME): main.o ClapTrap.o
	$(CXX) $(CXXFLAGS) main.o ClapTrap.o -o $(NAME)

main.o: main.cpp ClapTrap.h
	$(CXX) $(CXXFLAGS) -c main.cpp

ClapTrap.o: ClapTrap.cpp ClapTrap.h
	$(CXX) $(CXXFLAGS) -c ClapTrap.cpp

clean:
	rm -f main.o ClapTrap.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
