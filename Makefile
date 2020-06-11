NAME		:= Chess
COMPILER	:= g++

SRC			:= Chess.cpp Figures/Figure.cpp ChessRunGame.cpp ChessPutOnBoard.cpp \
			ChessFiguresGo.cpp Figures/Bishop.cpp Figures/RookIsCheckToKing.cpp \
			Figures/BishopIsCheckToKing.cpp  ChessLoadGame.cpp\
			Figures/King.cpp Figures/Knight.cpp Figures/Pawn.cpp Figures/Queen.cpp \
			Figures/Rook.cpp ChessSaveGame.cpp
EXTRA		:= ./extra/trimSpaces.cpp ./extra/ft_memset.cpp ./extra/isWhiteFigure.cpp
OBJ			:= $(SRC:.cpp=.o)
OBJ_EXTRA	:= $(EXTRA:.cpp=.o)
INCLUDE		:= -I . -I ./Figures/
# make:
# 	$(COMPILER) -o $(NAME) $(SRC) $(EXTRA) $(INCLUDE)

all: $(SRC) $(NAME)

$(NAME): $(OBJ) $(OBJ_EXTRA)
	$(COMPILER) $(OBJ) $(OBJ_EXTRA) $(INCLUDE) -o $@

.cpp.o:
	$(COMPILER) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_EXTRA)

fclean:
	rm -f $(NAME)

re: fclean make
