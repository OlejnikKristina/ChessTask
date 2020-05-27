
#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include <string>
#include <map>
#include <ctype.h>
#include <string.h>
#include "../shortcuts.hpp"

using std::string;

class	Figure
{
	protected:
	int			currPos[2];		// current figure position
	int			destPos[2];		// new figure position [y;x]
	char		color;
	string		destXY;
	string		currXY;

	public:
	Figure();
	Figure(char curretPos[3], char destPos[3], char color);
	void		errorWrongMove(const char *figure, const char *extra = "\0");
	char		putVal(char val);
	bool		isWhiteFigure(char figure);
	bool		isBlackFigure(char figure);
	void		updateFigureCoordinate(std::map <string, char> figures);
	void		initCoordinate(int moveFrom[2], int moveTo[2]);
};

#endif
