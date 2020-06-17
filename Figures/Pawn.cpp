
#include "Pawn.hpp"
#include "Figure.hpp"

Pawn::Pawn(){}

Pawn::~Pawn(){}

Pawn::Pawn(char current[3], char dest[3], char fcolor)
	:Figure(current, dest, fcolor) {}

bool	Pawn::checkMoveWhitePawn(char board[9][8])
{
	int		y, x;

	y = destPos[Y];
	x = destPos[X];
	if (!preCheck(x, y, "Pawn"))
		return (false);
	else if (currPos[X] == x && (currPos[Y] == y - 1) && !isFigure(board[y][x]))
		std::cout << " White pawn is moving.";
	else if (currPos[X] == x && (currPos[Y] == 2 && 4 == y)
		&& !isFigure(board[3][x]) && !isFigure(board[4][x]))
		std::cout << " I am going be the Queen!";
	else if (currPos[X] != H && x == currPos[X] + 1 && y == currPos[Y] + 1
		&& isBlackFigure(board[y][x]))
		std::cout << " White pawn attacks from left!";
	else if (currPos[X] != A && x == currPos[X] - 1 && y == currPos[Y] + 1
		&& isBlackFigure(board[y][x]))
		std::cout << " White pawn attacks from right!";
	else
	{
		moveError("Pawn");
		return (false);
	}
	return (true);
}

bool	Pawn::checkMoveBlackPawn(char board[9][8])
{
	int		y, x;

	y = destPos[Y];
	x = destPos[X];
	if (!preCheck(x, y, "Pawn"))
		return (false);
	else if (currPos[X] == x && (currPos[Y] == y + 1) && !isFigure(board[y][x]))
		std::cout << " Black pawn is moving.";
	else if (currPos[X] == x &&  (currPos[Y] == 7 && 5 == y)
		&& !isFigure(board[6][x]) && !isFigure(board[5][x]))
		std::cout << " Black pawn first move and already far";
	else if (currPos[X] != H && x == currPos[X] + 1 && y == currPos[Y] - 1
		&& isWhiteFigure(board[y][x]))
		std::cout << " Black pawn attacks from left!";
	else if (currPos[X] != A && x == currPos[X] - 1 && y == currPos[Y] - 1
		&& isWhiteFigure(board[y][x]))
		std::cout << " Black pawn attacks from right!";
	else
	{
		moveError("Pawn");
		return (false);
	}
	return (true);
}

bool	Pawn::isCheckToKing(char board[9][8])
{
	int	x, y;

	x = destPos[X];
	y = destPos[Y];
	if (color == 'w')
	{
		return (
		(board[y + 1][x + 1] == BKING) ||
		(board[y + 1][x - 1] == BKING));
	}
	else
	{
		return (
		(board[y - 1][x + 1] == KING) ||
		(board[y - 1][x - 1] == KING));
	}
	return (false);
}

bool	Pawn::checkMove(char board[9][8])
{
	if (!preCheck(destPos[X], destPos[Y], "Pawn"))
		return (false);
	else if (color == 'w')
		return (checkMoveWhitePawn(board));
	else if (color == 'b')
		return (checkMoveBlackPawn(board));
	return (true);
}
