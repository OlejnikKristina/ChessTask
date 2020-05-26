
#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Figure.hpp"

class		Bishop: public Figure
{
	public:
	Bishop();
	Bishop(char current[3], char dest[3]);
};

#endif
