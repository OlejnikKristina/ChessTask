
#include "Chess.hpp"

void		Chess::gameRules()
{
	std::cout << YELLOW <<
	"\n    **  Wellcome to console chess game  **\n\
  **  Two players should enter moves one after \
other in following format:\n\
  **  [current figure spot] [destination figure spot]\n\
  **  For example: e2 e4\n\
  **  Will move one of the white pawn 2 spots up\n" << RESET;
}

bool		Chess::substructMove(char move[], char direction[3])
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

bool		Chess::getMove()
{
	char		move[42];

	std::cout << " Enter move: ";
	std::cin.getline(move, 42);
	if (!substructMove(move, currPos))
		return (false);
	if (!substructMove(&move[2], destPos))
		return (false);
	return (true);
}

bool		Chess::moveFigure(map <string, char> &figures)
{
	string	color = "color";
	char	figure;
	char	current[3];
	char	dest[3];

	strncpy(current, (char const *) currPos, 3);
	strncpy(dest, (char const *) destPos, 3);
	figure = figures[currPos];
	if (figure == PAWN || figure == BPAWN)
		return (goPawn(current, dest, figures[color]));
	else if (figure == BISHOP|| figure == BBISHOP)
		return (goBishop(current, dest, figures[color]));
	else if (figure == KNIGHT || figure == BKNIGHT)
		return (goKnight(current, dest, figures[color]));
	else if (figure == ROOK || figure == BROOK)
		return (goRook(current, dest, figures[color]));
	else if (figure == QUEEN || figure == BQUEEN)
		return (goQueen(current, dest, figures[color]));
	else if (figure == KING || figure == BKING)
		return (goKing(current, dest, figures[color]));
	else
	{
		std::cout << "Ops.. [" << currPos << "] ";
		std::cout << "No such a figure on a board. Try again.\n";
		return (false);
	}
	return (true);
}

bool		Chess::runGame()
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << "  ** White's turn **\n";
		while (!getMove() || !moveFigure(figsWhite))
			;
		putFigureOnBoard(figsWhite[currPos], figsWhite);
		std::cout << "  ** Black's turn **\n";
		while (!getMove() || !moveFigure(figsBlack))
			;
		putFigureOnBoard(figsBlack[currPos], figsBlack);
	}
}
