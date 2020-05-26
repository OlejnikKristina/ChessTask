
#include "Knight.hpp"
#include "Figure.hpp"

Knight::Knight(char current[3], char dest[3], char fcolor)
	:Figure(current, dest, fcolor)
{
	std::cout << "I am Knight! [" << currPos << "] [" << destPos << "] ";
}