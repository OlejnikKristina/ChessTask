
#include "Figure.hpp"

Figure::Figure() {}

Figure::~Figure(){}

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


bool	Figure::preCheck(int destX, int destY, const char *figure)
{
	string	allowedChar;

	allowedChar = "abcdefgh";
	if (7 < destX || destX < 0 || destY <= 0 || 8 < destY ||
		allowedChar.find(destXY[0]) == string::npos)
	{
		std::cout << "RRRRx: " << destX << "Y: " << destY << '\0';
		moveError(figure);
		return (false);
	}
	return (true);
}

void	Figure::moveError(const char *figure, const char *extra)
{
	std::cout << RED <<"Illegal move for " << figure << extra;
	std::cout << ". Try again.\n" << RESET;
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

bool		Figure::isFigure(char figure)
{
	return (isWhiteFigure(figure) || isBlackFigure(figure));
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
