
#include "Knight.hpp"
#include "Figure.hpp"

Knight::Knight(char current[3], char dest[3], char fcolor)
	:Figure(current, dest, fcolor)
{
	std::cout << "I am Knight! x[" << destPos[X] << "] y[" << destPos[Y] << "] ";
}

Knight::~Knight(){}

bool	Knight::isChekcToKing(char board[9][8])
{

}

bool	Knight::checkMove(char board[9][8])
{
	bool	(Figure::*isEnemy)(char);
	int		x, y;

	x = destPos[X];
	y = destPos[Y];
	isEnemy = (color == 'w') ?
	(&Figure::isBlackFigure):(&Figure::isWhiteFigure);
	if (!preCheck(destPos[X], destPos[Y], "Knight"))
		return (false);
	if (currPos[Y] - 2 == y && A <= x && x <= H
		&& (currPos[X] + 1 == x  || currPos[X] - 1 == x)
		&& !(this->*isEnemy)(board[y][x]))
		return (true);
	else if (currPos[Y] - 1 == y && A <= x && x <= H
		&& (currPos[X] + 2 == x  || currPos[X] - 2 == x)
		&& !(this->*isEnemy)(board[y][x]))
		return (true);
		if (currPos[Y] + 2 == y && A <= x && x <= H
		&& (currPos[X] + 1 == x  || currPos[X] - 1 == x)
		&& !(this->*isEnemy)(board[y][x]))
		return (true);
	else if (currPos[Y] + 1 == y && A <= x && x <= H
		&& (currPos[X] + 2 == x  || currPos[X] - 2 == x)
		&& !(this->*isEnemy)(board[y][x]))
		return (true);
	moveError("knight");
	return (false);
}
