
NAME		:= Chess
COMPILER	:= g++

SRC			:= Chess.cpp Figure.cpp
EXTRA		:= extra/trimSpaces.cpp extra/ft_memset.cpp
INCLUDE		:= Chess.hpp

make:
	$(COMPILER) -o $(NAME) $(SRC) $(EXTRA) $(INCLUDE)
