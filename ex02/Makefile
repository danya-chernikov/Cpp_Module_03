CXX=c++

NAME=frag_trap

CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -O0 -g3

all: $(NAME)

# Yes, we still link ScavTrap.o, though we don't use it
$(NAME): main.o ClapTrap.o ScavTrap.o FragTrap.o
	$(CXX) $(CXXFLAGS) main.o ClapTrap.o ScavTrap.o FragTrap.o -o $(NAME)

main.o: main.cpp FragTrap.h
	$(CXX) $(CXXFLAGS) -c main.cpp

ClapTrap.o: ClapTrap.cpp ClapTrap.h
	$(CXX) $(CXXFLAGS) -c ClapTrap.cpp

ScavTrap.o: ScavTrap.cpp ScavTrap.h ClapTrap.h
	$(CXX) $(CXXFLAGS) -c ScavTrap.cpp

FragTrap.o: FragTrap.cpp FragTrap.h ClapTrap.h
	$(CXX) $(CXXFLAGS) -c FragTrap.cpp

clean:
	rm -f main.o ClapTrap.o ScavTrap.o FragTrap.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
