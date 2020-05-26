
#ifndef KING_HPP
#define KING_HPP

#include "Figure.hpp"

class		King: public Figure
{
	public:
	King();
	King(char current[3], char dest[3], char fcolor);
};

#endif
