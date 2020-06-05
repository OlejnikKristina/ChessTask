NAME		:= Chess
COMPILER	:= g++

SRC			:= Chess.cpp Figures/Figure.cpp ChessRunGame.cpp ChessPutOnBoard.cpp \
			ChessFiguresGo.cpp Figures/Bishop.cpp Figures/RookIsCheckToKing.cpp \
			Figures/BishopIsCheckToKing.cpp \
			Figures/King.cpp Figures/Knight.cpp Figures/Pawn.cpp Figures/Queen.cpp \
			Figures/Rook.cpp ChessSaveGame.cpp
EXTRA		:= extra/trimSpaces.cpp extra/ft_memset.cpp extra/isWhiteFigure.cpp
OBJ			:= $(SRC:.cpp=.o)
INCLUDE		:= -I . -I Figures/ Figures/Queen.hpp

make:
	$(COMPILER) -o $(NAME) $(SRC) $(EXTRA) $(INCLUDE)

# all: $(SRC) $(NAME)

# $(NAME): $(OBJ)
# 	$(COMPILER) -c $(OBJ) $(INCLUDE) -o $@

# .cpp.o:
# 	$(COMPILER) -c $< -o $@

fclean:
	rm -f $(NAME)

re: fclean make
