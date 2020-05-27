
NAME		:= Chess
COMPILER	:= g++

SRC			:= Chess.cpp Figures/Figure.cpp ChessRunGame.cpp ChessPutOnBoard.cpp \
			Figures/Bishop.cpp \
			Figures/King.cpp Figures/Knight.cpp Figures/Pawn.cpp Figures/Queen.cpp \
			Figures/Rook.cpp 
EXTRA		:= extra/trimSpaces.cpp extra/ft_memset.cpp extra/isWhiteFigure.cpp
INCLUDE		:= -I . -I Figures/ Figures/Queen.hpp

make:
	$(COMPILER) -o $(NAME) $(SRC) $(EXTRA) $(INCLUDE)
