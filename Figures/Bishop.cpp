
#include "Bishop.hpp"
#include "Figure.hpp"

Bishop::Bishop(char current[3], char dest[3])
	:Figure(current, dest)
{
	std::cout << "I am Bishop! [" << currPos << "] [" << destPos << "] ";
}