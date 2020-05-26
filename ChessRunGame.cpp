
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

	std::cout << "  Enter move: ";
	std::cin.getline(move, 42);
	if (!substructMove(move, currPos))
		return (false);
	if (!substructMove(&move[2], destPos))
		return (false);
	return (true);
}

bool		Chess::moveFigure(map <string, char> figures)
{
	char	figure;

	figure = figures[currPos];
	if (figure == PAWN || figure == BPAWN)
	{
		Pawn paw(currPos, destPos, figures["color"]);
		if (paw.chekMove(board) == false)
			return (false);
	}
	else if (figure == BISHOP|| figure == BBISHOP)
	{
		Bishop bishop(currPos, destPos, figures["color"]);
	}
	else if (figure == KNIGHT || figure == BKNIGHT)
	{
		Knight knight(currPos, destPos, figures["color"]);
	}
	else if (figure == ROOK || figure == BROOK)
	{
		Rook rook(currPos, destPos, figures["color"]);
	}
	else if (figure == QUEEN || figure == BQUEEN)
	{
		Queen queen(currPos, destPos, figures["color"]);
	}
	else if (figure == KING || figure == BKING)
	{
		King king(currPos, destPos, figures["color"]);
	}
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
	std::cout << "  ** White's move **\n";
	while (!getMove() || !moveFigure(figsWhite))
		;
	std::cout << "  ** Black's move **\n";
	while (!getMove() || !moveFigure(figsBlack))
		;
}
