
#include "Rook.hpp"
#include "Figure.hpp"

Rook::Rook(char current[3], char dest[3], char fcolor):Figure(current, dest, fcolor)
{
	std::cout << "I am Rook! x[" << currPos[0] << "] y[" << currPos[1] << "]\n";
}

bool	Rook::checkMoveRight(char board[9][8], bool(Figure::*isEnemy)(char))
{
	for (int x = currPos[X], y = currPos[Y]; x < destPos[X]; ++x)
	{
		if (board[y][x] != '\0' && x != destPos[X]
			&& !(this->*isEnemy)(board[y][x]))
		{
			moveError("Rook", "Obstacal from right. ");
			return (false);
		}
	}
	return (true);
}

bool	Rook::checkMoveLeft(char board[9][8], bool(Figure::*isEnemy)(char))
{
	for (int x = currPos[X], y = currPos[Y]; destPos[X] < x; --x)
	{
		if (board[y][x] != '\0' && x != destPos[X]
			&& !(this->*isEnemy)(board[y][x]))
		{
			moveError("Rook", "Obstacal from left. ");
			return (false);
		}
	}
	return (true);
}

bool	Rook::checkMoveUp(char board[9][8], bool(Figure::*isEnemy)(char))
{
	for (int y = currPos[Y], x = currPos[X]; destPos[Y] < y; ++y)
	{
		if (board[y][x] != '\0' && y != destPos[Y] 
			&& !(this->*isEnemy)(board[y][x]))
		{
			moveError("Rook", "Obstacal from top. ");
			return (false);
		}
	}
	return (true);
}

bool	Rook::checkMoveDown(char board[9][8], bool(Figure::*isEnemy)(char))
{
	for (int y = currPos[Y], x = currPos[X]; y < destPos[Y]; --y)
	{
		if (board[y][x] != '\0' && y != destPos[Y] 
			&& !(this->*isEnemy)(board[y][x]))
		{
			moveError("Rook", "Obstacal below. ");
			return (false);
		}
	}
	return (true);
}

bool	Rook::checkMove(char board[9][8])
{
	bool	(Figure::*isEnemy)(char);

	if (color == 'w')
		isEnemy = &Figure::isBlackFigure;
	else
		isEnemy = &Figure::isWhiteFigure;
	if (!preCheck(destPos[X], destPos[Y], "Rook"))
		return (false);
	if (currPos[Y] == destPos[Y] && currPos[X] < destPos[X])
		return (checkMoveLeft(board, isEnemy));
	else if (currPos[Y] == destPos[Y] && destPos[X] < currPos[X])
		return (checkMoveRight(board, isEnemy));
	else if (currPos[X] == destPos[X] && currPos[Y] < destPos[Y])
		return (checkMoveUp(board, isEnemy));
	else if (currPos[X] == destPos[X] && destPos[Y] < currPos[Y])
		return (checkMoveDown(board, isEnemy));
	else
	{
		moveError("Rook");
		return (false);
	}
	return (true);
}