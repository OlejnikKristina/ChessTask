
#include "Queen.hpp"
#include "Bishop.hpp"
#include "Rook.hpp"

Queen::Queen(char current[3], char dest[3], char fcolor)
	:Bishop(current, dest, fcolor), Rook(current, dest, fcolor)
{
	std::cout << "I am Queen! [" << currPos[0] << "] [" << currPos[1] << "] ";
}

Queen::~Queen() {}
