
#ifndef PAWN_HPP
#define PAWN_HPP

#include "Figure.hpp"

class		Pawn: public Figure
{
	public:
	Pawn();
	Pawn(char current[3], char dest[3], char color);
	bool			chekMove();
};

#endif
