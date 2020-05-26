
#ifndef ROOK_HPP
#define ROOK_HPP

#include "Figure.hpp"

class		Rook: public Figure
{
	public:
	Rook();
	Rook(char current[3], char dest[3]);
};

#endif
