
#include "King.hpp"
#include "Figure.hpp"

King::King(char current[3], char dest[3], char fcolor)
	:Figure(current, dest, fcolor)
{
	std::cout << "I am King! [" << currPos[0] << "] [" << currPos[1] << "] ";
}

bool	King::checkMove(char board[9][8])
{
	return (false);
}
