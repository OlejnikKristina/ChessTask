
#include "Chess.hpp"

void	Chess::gameRules()
{
	std::cout << BLUE <<
"\n    **  Wellcome to console chess game  **\n" << YELLOW
<< "  **  Two players should enter moves one after \
other in following format:\n\
  **  [current figure spot] [destination figure spot]\n\
  **  For example: e2 e4\n\
  **  Will move one of the white pawn 2 spots up\n" << BLUE
<< MAGENTA << " Options:\n" << GREEN <<
"  'start game'" << BLUE << " to start a new game\n" << GREEN <<
"  'restart game'" << BLUE << " to start a new game\n" << GREEN <<
"  'load game'" << BLUE << " to load a previosly saved game\n" << GREEN <<
"  'save game'" << BLUE << " to save a game\n" << GREEN <<
"  'exit'"<< BLUE << " to finish game\n" << RESET;
}

bool	Chess::substructMove(char move[], char direction[3])
{
	int		i;

	i = 0;
	while (move[i] && isspace(move[i]))
		i++;
	if (move[i] && move[i + 1])
	{
		direction[0] = (char)tolower(move[i]);
		direction[1] = (char)tolower(move[i + 1]);
		move[i] = ' ';
		move[i + 1] = ' ';
	}
	else
	{
		std::cout << "Error no move entered, try again\n";
		return (false);
	}
	direction[2] = '\0';
	return (true);
}

bool	Chess::getMove()
{
	char	move[42];

	std::cout << GREEN << " Enter move: " << RESET;
	std::cin.getline(move, 42);
	if (strcmp(move, "exit") == 0)
		exit(0);
	else if (strcmp(move, "restart game") == 0)
	{
		Chess();
		exit(0);
	}
	else if (strcmp(move, "save game") == 0)
		return (saveGame());
	else if (!substructMove(move, currPos))
		return (false);
	else if (!substructMove(&move[2], destPos))
		return (false);
	return (true);
}

bool	Chess::moveFigure(map <string, char> &figures)
{
	string	key = "color";
	char	figure;
	char	current[3];
	char	dest[3];
	show_figures(figures);			//TEST
	strncpy(current, (char const *) currPos, 3);
	strncpy(dest, (char const *) destPos, 3);
	figure = figures[currPos];
	color = figures[key];
	if (figure == PAWN || figure == BPAWN)
	{
		Pawn pawn(current, dest, color);
		return (goFigure(&pawn));
	}
	else if (figure == BISHOP|| figure == BBISHOP)
	{
		Bishop bishop(current, dest, color);
		return (goFigure(&bishop));
	}
	else if (figure == KNIGHT || figure == BKNIGHT)
	{
		Knight knight(current, dest, color);
		return (goFigure(&knight));
	}
	else if (figure == ROOK || figure == BROOK)
	{
		Rook rook(current, dest, color);
		return (goFigure(&rook));
	}
	else if (figure == QUEEN || figure == BQUEEN)
		return (goQueen(current, dest));
	else if (figure == KING || figure == BKING)
		return (goKing(current, dest));
	else
	{
		std::cout << " Ops.. [" << currPos << "] ";
		std::cout << "No such a figure on a board. Try again.\n";
		return (false);
	}
	return (true);
}

bool	Chess::runGame()
{
	while (winner == false)
	{
		std::cout << "  ** White's turn **\n";
		while (!getMove() || !moveFigure(figsWhite))
			;
		putFigureOnBoard(figsWhite[currPos], figsWhite);
		checkToWhite = false;
		std::cout << "  ** Black's turn **\n";
		while (!getMove() || !moveFigure(figsBlack))
			;
		putFigureOnBoard(figsBlack[currPos], figsBlack);
		checkToBlack = false;
	}
	getWinner();
}
