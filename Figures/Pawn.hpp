
#ifndef PAWN_HPP
#define PAWN_HPP

#include "Figure.hpp"

class		Pawn: public Figure
{
	public:
	Pawn();
	Pawn(char currentPos[3], char destPos[3]);
};

#endif
