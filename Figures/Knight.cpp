
#include "Knight.hpp"
#include "Figure.hpp"

Knight::Knight(char current[3], char dest[3])
	:Figure(current, dest)
{
	std::cout << "I am Knight! [" << currPos << "] [" << destPos << "] ";
}