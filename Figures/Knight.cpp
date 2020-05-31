
#include "Knight.hpp"
#include "Figure.hpp"

Knight::Knight(char current[3], char dest[3], char fcolor)
	:Figure(current, dest, fcolor) {}

Knight::~Knight(){}

bool	Knight::doesKnightAttack(char board[9][8], int x, int y, char foeKing)
{
	if (0 <= x && x <= 7 && 1 <= y && y <= 8)
		return ((board[y][x] == foeKing));
	return (false);
}

/*  Check all of the 8 possible position for an opponent's King */

bool	Knight::isCheckToKing(char board[9][8])
{
	char	foeKing;

	if (color == 'w')
		foeKing = BKING;
	else if (color == 'b')
		foeKing = KING;
	return (
		doesKnightAttack(board, destPos[X] + 1, destPos[Y] + 2, foeKing) ||
		doesKnightAttack(board, destPos[X] - 1, destPos[Y] + 2, foeKing) ||
		doesKnightAttack(board, destPos[X] + 1, destPos[Y] - 2, foeKing) ||
		doesKnightAttack(board, destPos[X] - 1, destPos[Y] - 2, foeKing) ||
		doesKnightAttack(board, destPos[X] + 2, destPos[Y] + 1, foeKing) ||
		doesKnightAttack(board, destPos[X] + 2, destPos[Y] - 1, foeKing) ||
		doesKnightAttack(board, destPos[X] - 2, destPos[Y] + 1, foeKing) ||
		doesKnightAttack(board, destPos[X] - 2, destPos[Y] - 1, foeKing)
	);
}

bool	Knight::checkMove(char board[9][8])
{
	bool	(Figure::*isEnemy)(char);
	int		x, y;

	x = destPos[X];
	y = destPos[Y];
	isEnemy = (color == 'w') ?
	(&Figure::isBlackFigure) : (&Figure::isWhiteFigure);
	if (!preCheck(destPos[X], destPos[Y], "Knight"))
		return (false);
	if (currPos[Y] - 2 == y && A <= x && x <= H &&
	(currPos[X] + 1 == x  || currPos[X] - 1 == x) &&
	((this->*isEnemy)(board[y][x]) || !isFigure(board[y][x])))
		return (true);
	else if (currPos[Y] - 1 == y && A <= x && x <= H &&
	(currPos[X] + 2 == x  || currPos[X] - 2 == x) &&
	((this->*isEnemy)(board[y][x]) || !isFigure(board[y][x])))
		return (true);
	if (currPos[Y] + 2 == y && A <= x && x <= H &&
	(currPos[X] + 1 == x  || currPos[X] - 1 == x) &&
	((this->*isEnemy)(board[y][x]) || !isFigure(board[y][x])))
		return (true);
	else if (currPos[Y] + 1 == y && A <= x && x <= H &&
	(currPos[X] + 2 == x  || currPos[X] - 2 == x) &&
	((this->*isEnemy)(board[y][x]) || !isFigure(board[y][x])))
		return (true);
	moveError("knight");
	return (false);
}
