
#include "Pawn.hpp"
#include "Figure.hpp"

Pawn::Pawn(){}

Pawn::Pawn(char current[3], char dest[3], char fcolor)
	:Figure(current, dest, fcolor)
{
	std::cout << "I am pawn!" \
	<< "Curr pos: x ["<< currPos[0] << "] y [" << currPos[1] << "] " \
	<< "Dest pos: x ["<< destPos[0] << "] y [" << destPos[1] << "] \n";
}

bool	Pawn::checkMoveWhitePawn(char board[9][8])
{
	if (H < destPos[X] || 8 < destPos[Y])
	{
		errorWrongMove("Figure");
		return (false);
	}
	else if (currPos[X] == destPos[X] && (currPos[Y] == destPos[Y] - 1))
		std::cout << "  White pawn is moving.\n";
	else if (currPos[X] == destPos[X] && 
	(currPos[Y] == 2 && 2 == destPos[Y] - 2))
		std::cout << "  White pawn first move and already far\n";
	else if (currPos[X] != H && destPos[X] == currPos[X] + 1
	&& destPos[Y] == currPos[Y] + 1
	&& isBlackFigure(board[destPos[Y]][destPos[X]]))
		std::cout << "  White pawn attacks from left!\n";
	else if (currPos[X] != A && destPos[X] == currPos[X] - 1
	&& destPos[Y] == currPos[Y] + 1
	&& isBlackFigure(board[destPos[Y]][destPos[X]]))
		std::cout << "  White pawn attacks from right!\n";
	else
	{
		errorWrongMove("Pawn");
		return (false);
	}
	return (true);
}

bool	Pawn::checkMoveBlackPawn(char board[9][8])
{
	if (H < destPos[X] || 8 < destPos[Y])
	{
		errorWrongMove("Pawn");
		return (false);
	}
	else if (currPos[X] == destPos[X] && (currPos[Y] == destPos[Y] + 1))
		std::cout << "  Black pawn is moving.\n";
	else if (currPos[X] == destPos[X] && 
	(currPos[Y] == 7 && 7 == destPos[Y] + 2))
		std::cout << "  Black pawn first move and already far\n";
	else if (currPos[X] != H && destPos[X] == currPos[X] + 1
	&& destPos[Y] == currPos[Y] - 1
	&& isBlackFigure(board[destPos[Y]][destPos[X]]))
		std::cout << "  Black pawn attacks from left!\n";
	else if (currPos[X] != A && destPos[X] == currPos[X] - 1
	&& destPos[Y] == currPos[Y] - 1
	&& isBlackFigure(board[destPos[Y]][destPos[X]]))
		std::cout << "  Black pawn attacks from right!\n";
	else
	{
		errorWrongMove("Pawn");
		return (false);
	}
	return (true);
}

bool	Pawn::chekMove(char board[9][8])
{
	if (color == 'w')
		return (checkMoveWhitePawn(board));
	else
		return (checkMoveBlackPawn(board));
	return (true);
}
