
#include "Knight.hpp"
#include "Figure.hpp"

Knight::Knight(char current[3], char dest[3], char fcolor)
	:Figure(current, dest, fcolor)
{
	std::cout << "I am Knight! x[" << destPos[X] << "] y[" << destPos[Y] << "] ";
}

bool	Knight::checkWhiteKnight(char board[9][8])
{
	int x, y;

	x = destPos[X];
	y = destPos[Y];
	if (currPos[Y] + 2 == y && A <= x && x <= H
		&& (currPos[X] + 1 == x  || currPos[X] - 1 == x)
		&& !isWhiteFigure(board[y][x]))
		return (true);
	else if (currPos[Y] + 1 == y && A <= x && x <= H
		&& (currPos[X] + 2 == x  || currPos[X] - 2 == x)
		&& !isWhiteFigure(board[y][x]))
		return (true);
	moveError("white knight");
	return (false);
}

bool	Knight::checkBlackKnight(char board[9][8])
{
	int x, y;

	x = destPos[X];
	y = destPos[Y];
	if (currPos[Y] - 2 == y && A <= x && x <= H
		&& (currPos[X] + 1 == x  || currPos[X] - 1 == x)
		&& !isBlackFigure(board[y][x]))
		return (true);
	else if (currPos[Y] - 1 == y && A <= x && x <= H
		&& (currPos[X] + 2 == x  || currPos[X] - 2 == x)
		&& !isBlackFigure(board[y][x]))
		return (true);
	moveError("black knight");
	return (false);
}

bool	Knight::checkMove(char board[9][8])
{
	if (!preCheck(destPos[X], destPos[Y], "Knight"))
		return (false);
	else if (color == 'w')
		return (checkWhiteKnight(board));
	else
		return (checkBlackKnight(board));
	return (false);
}
