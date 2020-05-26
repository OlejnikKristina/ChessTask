
#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "Figure.hpp"

class		Queen: public Figure
{
	public:
	Queen();
	Queen(char current[3], char dest[3], char fcolor);
};

#endif
