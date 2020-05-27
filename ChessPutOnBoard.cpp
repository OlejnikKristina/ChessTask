
#include "Chess.hpp"

void		Chess::updateFigureSpot(std::map <string, char> &figures, \
			char exSpot1[3], char newSpot1[3])
{
	char		tempFigure;
	string		exSpot;
	string		newSpot;

	exSpot = exSpot1;
	newSpot = newSpot1;
	tempFigure = figures[exSpot];
	figures.erase(exSpot);
	figures[newSpot] = tempFigure;
}

bool	Chess::putFigureOnBoard(char figure, std::map <string, char> &figures)
{
	board[moveFrom[Y]][moveFrom[X]] = '\0';
	board[moveTo[Y]][moveTo[X]] = figure;
	boardPrint();
	updateFigureSpot(figsBlack, currPos, destPos);
	return (true);
}
