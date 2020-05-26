
#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include <string>
#include <map>
#include <ctype.h>
#include <string.h>

using std::string;

class	Figure
{
	protected:
	char		currPos[3];		// current figure position
	char		destPos[3];		// new figure position

	public:
	Figure();
	Figure(char curretPos[3], char destPos[3]);
};

#endif
