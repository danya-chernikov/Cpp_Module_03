CXX=c++

NAME=scav_trap

CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -O0 -g3

all: $(NAME)

$(NAME): main.o ClapTrap.o ScavTrap.o
	$(CXX) $(CXXFLAGS) main.o ClapTrap.o ScavTrap.o -o $(NAME)

main.o: main.cpp ScavTrap.h
	$(CXX) $(CXXFLAGS) -c main.cpp

ClapTrap.o: ClapTrap.cpp ClapTrap.h
	$(CXX) $(CXXFLAGS) -c ClapTrap.cpp

ScavTrap.o: ScavTrap.cpp ScavTrap.h ClapTrap.h
	$(CXX) $(CXXFLAGS) -c ScavTrap.cpp

clean:
	rm -f main.o ClapTrap.o ScavTrap.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
