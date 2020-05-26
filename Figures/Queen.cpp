
#include "Queen.hpp"
#include "Figure.hpp"

Queen::Queen(char current[3], char dest[3])
	:Figure(current, dest)
{
	std::cout << "I am Queen! [" << currPos << "] [" << destPos << "] ";
}