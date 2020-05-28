
#include "Queen.hpp"
#include "Figure.hpp"

Queen::Queen(char current[3], char dest[3], char fcolor)
	:Figure(current, dest, fcolor)
{
	std::cout << "I am Queen! [" << currPos[0] << "] [" << currPos[1] << "] ";
}

bool	Queen::checkMove(char board[9][8])
{
	
	return (false);
}
