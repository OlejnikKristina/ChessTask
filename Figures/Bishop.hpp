
#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Figure.hpp"

class		Bishop: public Figure
{
	public:
	Bishop();
	~Bishop();
	Bishop(char current[3], char dest[3], char fcolor);
	bool	checkMove(char board[9][8]) override;
	bool 	isCheckToKing(char board[9][8]) override;
	bool	checkDiagonalLeftUp(char board[9][8], bool(Figure::*isEnemy)(char));
	bool	checkDiagonalRightUp(char board[9][8], bool(Figure::*isEnemy)(char));
	bool	checkDiagonalLeftDown(char board[9][8], bool(Figure::*isEnemy)(char));
	bool	checkDiagonalRightDown(char board[9][8], bool(Figure::*isEnemy)(char));
	bool 	isCheckToKingDiagLeftUp(char board[9][8], int x, int y, char foeKing);
	bool 	isCheckToKingDiagLeftDown(char board[9][8], int x, int y, char foeKing);
	bool 	isCheckToKingDiagRightUp(char board[9][8], int x, int y, char foeKing);
	bool 	isCheckToKingDiagRightDown(char board[9][8], int x, int y, char foeKing);
};

#endif
