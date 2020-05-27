
#include "Figure.hpp"

void	Figure::errorWrongMove(const char *figure, const char *extra)
{
	std::cout << RED <<"Illigal move for " << figure << extra;
	std::cout << ". Try again.\n" << RESET;
	std::cout << "Syntax: [[letter column][num row]] [[letter column][num row]]\n";
}

void		Figure::initCoordinate(int moveFrom[2], int moveTo[2])
{
	moveFrom[X] = currPos[X];
	moveFrom[Y] = currPos[Y];
	moveTo[X] = destPos[X];
	moveTo[Y] = destPos[Y];
}

bool	Figure::isBlackFigure(char figure)
{
	return (
	figure == BPAWN || figure == BBISHOP || figure == BKNIGHT
	|| figure == BROOK || figure == BQUEEN || figure == BKING
	);
}

bool	Figure::isWhiteFigure(char figure)
{
	return (
	figure == PAWN || figure == BISHOP || figure == KNIGHT
	|| figure == ROOK || figure == QUEEN || figure == KING
	);
}

char		Figure::putVal(char val)
{
	if (val == 'a') return (A);
	else if (val == 'b') return (B);
	else if (val == 'c') return (C);
	else if (val == 'd') return (D);
	else if (val == 'e') return (E);
	else if (val == 'f') return (F);
	else if (val == 'g') return (G);
	else if (val == 'h') return (H);
	return ('\0');
}

Figure::Figure() {}

Figure::Figure(char current[3], char dest[3], char fcolor)
{
	destXY = dest;
	currXY = current;
	currPos[X] = putVal(current[0]);
	current[X] = ' ';
	currPos[Y] = atoi((const char *)&current[1]);
	destPos[X] = putVal(dest[0]);
	dest[X] = ' ';
	destPos[Y] = atoi((const char *)&dest[1]);
	color = fcolor;
}
