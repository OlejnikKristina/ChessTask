
#include "Queen.hpp"
#include "Bishop.hpp"
#include "Rook.hpp"

Queen::Queen(char current[3], char dest[3], char fcolor)
	:Bishop(current, dest, fcolor), Rook(current, dest, fcolor)
{
	std::cout << "I am Queen! Bishop x[" << Bishop::currPos[X] << "] [" << Bishop::currPos[Y] << "]\n";
	std::cout << "Rook x[" << Rook::currPos[X] << "] [" << Rook::currPos[Y] << "] ";
}

Queen::~Queen() {}
