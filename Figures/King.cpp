
#include "King.hpp"
#include "Figure.hpp"

King::King(char current[3], char dest[3])
	:Figure(current, dest)
{
	std::cout << "I am King! [" << currPos << "] [" << destPos << "] ";
}