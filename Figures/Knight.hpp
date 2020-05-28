
#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Figure.hpp"

class		Knight: public Figure
{
	public:
	Knight();
	~Knight();
	Knight(char current[3], char dest[3], char fcolor);
	bool	checkMove(char board[9][8]);
	bool	checkBlackKnight(char board[9][8]);
	bool	checkWhiteKnight(char board[9][8]);
};

#endif
