
#include "Rook.hpp"
#include "Figure.hpp"

Rook::Rook(char current[3], char dest[3])
	:Figure(current, dest)
{
	std::cout << "I am Rook! [" << currPos << "] [" << destPos << "] ";
}