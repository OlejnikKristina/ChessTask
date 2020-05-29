
#ifndef KING_HPP
#define KING_HPP

#include "Figure.hpp"

class		King: public Figure
{
	public:
	King();
	King(char current[3], char dest[3], char fcolor);
	bool	checkMove(char board[9][8]);
	bool	checkMate(char board[9][8]);
};

#endif
