
#include "Bishop.hpp"
#include "Figure.hpp"

bool	Bishop::isCheckToKing(char board[9][8])
{
	char	foeKing;

	if (color == 'w') foeKing = BKING;
	else if (color == 'b') foeKing = KING;
	return (
		isCheckToKingDiagRightUp(board, destPos[X] + 1, destPos[Y] + 1, foeKing) ||
		isCheckToKingDiagRightDown(board, destPos[X] + 1, destPos[Y] - 1, foeKing) ||
		isCheckToKingDiagLeftUp(board, destPos[X] - 1, destPos[Y] + 1, foeKing) ||
		isCheckToKingDiagLeftDown(board, destPos[X] - 1, destPos[Y] - 1, foeKing)
	);
}

bool	Bishop::isCheckToKingDiagLeftDown(char board[9][8], int x, int y, char foeKing)
{
	while (1 <= y)
	{
		if (isFigure(board[y][x]))
			break ;
		y--;
		x--;
	}
	return (board[y][x] == foeKing);
}

bool	Bishop::isCheckToKingDiagLeftUp(char board[9][8], int x, int y, char foeKing)
{
	while (y <= 8)
	{
		if (isFigure(board[y][x]))
			break ;
		y++;
		x--;
	}
	return (board[y][x] == foeKing);
}

bool	Bishop::isCheckToKingDiagRightUp(char board[9][8], int x, int y, char foeKing)
{
	while (y <= 8)
	{
		if (isFigure(board[y][x]))
			break ;
		y++;
		x++;
	}
	return (board[y][x] == foeKing);
}

bool	Bishop::isCheckToKingDiagRightDown(char board[9][8], int x, int y, char foeKing)
{
	while (1 <= y)
	{
		if (isFigure(board[y][x]))
			break ;
		y--;
		x++;
	}
	return (board[y][x] == foeKing);
}
