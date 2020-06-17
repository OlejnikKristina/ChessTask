NAME		:= Chess
COMPILER	:= g++
BOT			:= ./StockfishLinuxBot/stockfish

SRC			:=  StockfishBot.cpp Chess.cpp Figures/Figure.cpp ChessRunGame.cpp ChessPutOnBoard.cpp \
			ChessFiguresGo.cpp Figures/Bishop.cpp Figures/RookIsCheckToKing.cpp \
			Figures/BishopIsCheckToKing.cpp  ChessLoadGame.cpp \
			Figures/King.cpp Figures/Knight.cpp Figures/Pawn.cpp Figures/Queen.cpp \
			Figures/Rook.cpp ChessSaveGame.cpp
EXTRA		:= ./extra/trimSpaces.cpp ./extra/ft_memset.cpp ./extra/isWhiteFigure.cpp
OBJ			:= $(SRC:.cpp=.o)
OBJ_EXTRA	:= $(EXTRA:.cpp=.o)
INCLUDE		:= -I . -I ./Figures/

all: $(SRC) $(NAME)

$(NAME): $(OBJ) $(OBJ_EXTRA) $(BOT)
	$(COMPILER) $(OBJ) $(OBJ_EXTRA) $(INCLUDE) -o $@

$(BOT):
	@make -C ./StockfishLinuxBot/ -s build ARCH=x86-64 COMP=gcc

.cpp.o:
	$(COMPILER) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_EXTRA)
	@echo "\033[0;32mDeleted objects files\033[0m"
	@make -C ./StockfishLinuxBot/ -s clean

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;32mDeleted ./Chess \033[0m"

re: fclean make
