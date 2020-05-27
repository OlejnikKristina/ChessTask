
#include "Rook.hpp"
#include "Figure.hpp"

Rook::Rook(char current[3], char dest[3], char fcolor):Figure(current, dest, fcolor)
{
	std::cout << "I am Rook! x[" << currPos[0] << "] y[" << currPos[1] << "]\n";
}

bool	Rook::checkMoveRight(char board[9][8], bool(Figure::*isEnemy)(char))
{
	for (int x = currPos[X] + 1, y = currPos[Y]; x <= destPos[X]; x++)
	{
		if (x == destPos[X] && (this->*isEnemy)(board[y][x]))
		{
			std::cout << "Blood for Kingdom!";
			return (true);
		}
		else if (isWhiteFigure(board[y][x]) || isBlackFigure(board[y][x]))
		{
			moveError("Rook", "Obstacal from right");
			return (false);
		}
	}
	return (true);
}

bool	Rook::checkMoveLeft(char board[9][8], bool(Figure::*isEnemy)(char))
{
	for (int x = currPos[X] - 1, y = currPos[Y]; destPos[X] <= x; x--)
	{
		if (x == destPos[X] && (this->*isEnemy)(board[y][x]))
		{
			std::cout << "Rook", " Fight for the Queen!";
			return (true);
		}
		else if (isWhiteFigure(board[y][x]) || isBlackFigure(board[y][x]))
		{
			moveError("Rook", " Obstacal from right");
			return (false);
		}
	}
	return (true);
}

bool	Rook::checkMoveUp(char board[9][8], bool(Figure::*isEnemy)(char))
{
	for (int y = currPos[Y] + 1, x = currPos[X]; y <= destPos[Y]; y++)
	{
		if (y == destPos[Y] && (this->*isEnemy)(board[y][x]))
		{
			std::cout << " Kill them all. ";
			return (true);
		}
		else if (isWhiteFigure(board[y][x]) || isBlackFigure(board[y][x]))
		{
			moveError("Rook", " Obstacal adove");
			return (false);
		}
	}
	return (true);
}

bool	Rook::checkMoveDown(char board[9][8], bool(Figure::*isEnemy)(char))
{
	for (int y = currPos[Y] - 1, x = currPos[X]; destPos[Y] <= y; y--)
	{
		if (y == destPos[Y] && (this->*isEnemy)(board[y][x]))
		{
			std::cout << " Go to a better world. ";
			return (true);
		}
		else if (isWhiteFigure(board[y][x]) || isBlackFigure(board[y][x]))
		{
			moveError("Rook", " Obstacal below");
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
	if (currPos[Y] == destPos[Y] && currPos[X] > destPos[X])
		return (checkMoveLeft(board, isEnemy));
	else if (currPos[Y] == destPos[Y] && currPos[X] < destPos[X])
		return (checkMoveRight(board, isEnemy));
	else if (currPos[X] == destPos[X] && currPos[Y] < destPos[Y])
		return (checkMoveUp(board, isEnemy));
	else if (currPos[X] == destPos[X] && currPos[Y] > destPos[Y])
		return (checkMoveDown(board, isEnemy));
	else
	{
		moveError("Rook");
		return (false);
	}
	return (true);
}