
#include "Rook.hpp"
#include "Figure.hpp"

/** 	Search for opponent King Up		 **/

bool Rook::isCheckToKingUp(char board[9][8], int x, int y, char foeKing)
{
	while (y <= 8)
	{
		if (isFigure(board[y][x]))
			break ;
		y++;
	}
	return (board[y][x] == foeKing);
}

/* Search for opponent King Down */

bool Rook::isCheckToKingDown(char board[9][8], int x, int y, char foeKing)
{
	while (1 <= y)
	{
		if (isFigure(board[y][destPos[X]]))
			break ;
		y--;
	}
	return (board[y][x] == foeKing);
}

/* Search for opponent King from Right */

bool Rook::isCheckToKingRight(char board[9][8], int x, int y, char foeKing)
{
	while (x <= 7)
	{
		if (isFigure(board[y][destPos[X]]))
			break ;
		x++;
	}
	return (board[y][x] == foeKing);
}

/* Search for opponent King from Left */

bool Rook::isCheckToKingLeft(char board[9][8], int x, int y, char foeKing)
{
	while (0 <= x)
	{
		if (isFigure(board[y][destPos[X]]))
			break ;
		x--;
	}
	return (board[y][x] == foeKing);
}

bool Rook::isCheckToKing(char board[9][8])
{
	char	foeKing;
	int		y, x;

	foeKing = (color == 'w') ? BKING : KING;
	return (
		isCheckToKingUp(board, destPos[X], destPos[Y] + 1, foeKing) ||
		isCheckToKingDown(board, destPos[X], destPos[Y] - 1, foeKing) ||
		isCheckToKingLeft(board, destPos[X] - 1, destPos[Y], foeKing) ||
		isCheckToKingRight(board, destPos[X] + 1, destPos[Y], foeKing)
	);
}
