
#include "Chess.hpp"

bool	Chess::putFigureOnBoard(char figure)
{
	std::cout << "moveTo[Y] " << moveTo[Y] << '\n';
	std::cout << "moveTo[X] " << moveTo[X] << '\n';
	std::cout << "currPos: " << currPos << '\n';
	std::cout << "figure " << figure << '\n';
	board[moveFrom[Y]][moveFrom[X]] = '\0';
	board[moveTo[Y]][moveTo[X]] = figure;
	boardPrint();
	return (true);
}
