
#include "Bishop.hpp"
#include "Figure.hpp"

Bishop::Bishop(char current[3], char dest[3], char fcolor)
	:Figure(current, dest, fcolor)
{
	std::cout << "I am Bishop! [" << currPos[0] << "] [" << currPos[1] << "] ";
}