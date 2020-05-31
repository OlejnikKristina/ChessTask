
#ifndef ROOK_HPP
#define ROOK_HPP

#include "Figure.hpp"

class		Rook: public Figure
{
	public:
	Rook();
	~Rook();
	Rook(char current[3], char dest[3], char fcolor);
	bool	checkMove(char board[9][8]) override;
	bool	checkMoveLeft(char board[9][8], bool(Figure::*isEnemy)(char));
	bool	checkMoveRight(char board[9][8], bool(Figure::*isEnemy)(char));
	bool	checkMoveUp(char board[9][8], bool(Figure::*isEnemy)(char));
	bool	checkMoveDown(char board[9][8], bool(Figure::*isEnemy)(char));
	bool	isCheckToKing(char board[9][8]);
	bool	isCheckToKingUp(char board[9][8], int x, int y, char foeKing);
	bool	isCheckToKingDown(char board[9][8], int x, int y, char foeKing);
	bool	isCheckToKingRight(char board[9][8], int x, int y, char foeKing);
	bool	isCheckToKingLeft(char board[9][8], int x, int y, char foeKing);
};

#endif
