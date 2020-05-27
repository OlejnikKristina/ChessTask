
#include "Bishop.hpp"
#include "Figure.hpp"

Bishop::Bishop(char current[3], char dest[3], char fcolor)
	:Figure(current, dest, fcolor)
{
	std::cout << "I am Bishop! \n";
}
// if (x == destPos[X] && y == destPos[Y] && (this->*isEnemy)(board[y][x]))
	// return (true);
		// if (x == destPos[X] && y != destPos[Y])
		// 	return (false);
		// else if (y == destPos[Y] && x != destPos[X])
		// 	return (false);

bool	Bishop::checkDiagonalLeftUp(char board[9][8], bool(Figure::*isEnemy)(char))
{
	int		x, y;

	x = currPos[X];
	y = currPos[Y];
	while (destPos[X] <= --x && ++y <= destPos[Y])
	{
		if (x == destPos[X] && y == destPos[Y] &&
			((this->*isEnemy)(board[y][x]) || !isFigure(board[y][x])))
			return (true);
		else if (isFigure(board[y][x]))
			break ;
	}
	moveError("Bishop");
	return (false);
}

bool	Bishop::checkDiagonalRightUp(char board[9][8], bool(Figure::*isEnemy)(char))
{
	int		x, y;

	x = currPos[X];
	y = currPos[Y];
	while (++x <= destPos[X] && ++y <= destPos[Y])
	{
		if (x == destPos[X] && y == destPos[Y] &&
		((this->*isEnemy)(board[y][x]) || !isFigure(board[y][x])))
			return (true);
		else if (isFigure(board[y][x]))
			break ;
	}
	moveError("Bishop");
	return (false);
}

bool	Bishop::checkDiagonalLeftDown(char board[9][8], bool(Figure::*isEnemy)(char))
{
	int		x, y;

	x = currPos[X];
	y = currPos[Y];
	while (destPos[X] <= --x && destPos[Y] <= --y)
	{
		if (x == destPos[X] && y == destPos[Y] &&
			((this->*isEnemy)(board[y][x]) || !isFigure(board[y][x])))
			return (true);
		else if (isFigure(board[y][x]))
			break ;
	}
	moveError("Bishop", " Obstacal left below");
	return (false);
}

bool	Bishop::checkDiagonalRightDown(char board[9][8], bool(Figure::*isEnemy)(char))
{
	int		x, y;

	x = currPos[X];
	y = currPos[Y];
	while (++x <= destPos[X] && destPos[Y] <= --y)
	{
		if (x == destPos[X] && y == destPos[Y] &&
			((this->*isEnemy)(board[y][x]) || !isFigure(board[y][x])))
			return (true);
		else if (isFigure(board[y][x]))
			break ;
	}
	moveError("Bishop", " Obstacal below");
	return (false);
}

bool	Bishop::checkMove(char board[9][8])
{
	bool	(Figure::*isEnemy)(char);

	isEnemy = (color == 'w') ?
	(&Figure::isBlackFigure):(&Figure::isWhiteFigure);
	if (!preCheck(destPos[X], destPos[Y], "Bishop"))
		return (false);
		
	if (destPos[X] > currPos[X] && destPos[Y] > currPos[Y])
		return (checkDiagonalRightUp(board, isEnemy));

	else if (destPos[X] < currPos[X] && destPos[Y] > currPos[Y])
		return (checkDiagonalLeftUp(board, isEnemy));

	else if (destPos[X] > currPos[X] && destPos[Y] < currPos[Y])
		return (checkDiagonalRightDown(board, isEnemy));

	else if (destPos[X] < currPos[X] && destPos[Y] < currPos[Y])
		return (checkDiagonalLeftDown(board, isEnemy));
	return (false);
}
