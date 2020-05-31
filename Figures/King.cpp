
#include "King.hpp"
#include "Figure.hpp"

King::King(char current[3], char dest[3], char fcolor)
	:Figure(current, dest, fcolor){}

bool	King::isCheckToKing(char board[9][8])
{
	return (false);
}

bool	King::checkMate(char board[9][8])
{
	int x, y;

	x = destPos[X];
	y = destPos[Y];
	return (
	( x + 1 <= 7 && !isFigure(board[y][x + 1])) ||
	(0 <= x - 1 && !isFigure(board[y][x - 1])) ||
	(0 <= y - 1 && !isFigure(board[y - 1][x])) ||
	(y + 1 <= 8 && !isFigure(board[y + 1][x]))
	);
}

bool	King::checkMove(char board[9][8])
{
	bool	res;

	if (!preCheck(destPos[X], destPos[Y], "King"))
		return (false);
	if (color == 'w')
		res = isBlackFigure(board[destPos[Y]][destPos[X]]);
	else
		res = isWhiteFigure(board[destPos[Y]][destPos[X]]);
	if (res == false)
		std::cout \
		<< RED << "  ** King can't hit own solder!\n" << RESET;
	return (res);
}
