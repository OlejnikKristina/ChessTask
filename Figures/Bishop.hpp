
#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Figure.hpp"

class		Bishop: public Figure
{
	public:
	Bishop();
	Bishop(char current[3], char dest[3], char fcolor);
	bool	checkMove(char board[9][8]);
	bool	checkDiagonalLeftUp(char board[9][8], bool(Figure::*isEnemy)(char));
	bool	checkDiagonalRightUp(char board[9][8], bool(Figure::*isEnemy)(char));
	bool	checkDiagonalLeftDown(char board[9][8], bool(Figure::*isEnemy)(char));
	bool	checkDiagonalRightDown(char board[9][8], bool(Figure::*isEnemy)(char));
};

#endif
