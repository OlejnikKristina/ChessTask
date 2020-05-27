
#include "Rook.hpp"
#include "Figure.hpp"

Rook::Rook(char current[3], char dest[3], char fcolor)
	:Figure(current, dest, fcolor)
{
	std::cout << "I am Rook! x[" << currPos[0] << "] y[" << currPos[1] << "]\n";
}