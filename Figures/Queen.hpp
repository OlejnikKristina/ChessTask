
#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "Bishop.hpp"
#include "Rook.hpp"

class		Queen: public Bishop, public Rook
{
	public:
	Queen();
	~Queen();
	Queen(char current[3], char dest[3], char fcolor);
};

#endif
