
#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "Chess.hpp"

using std::string;

class	Figure
{
	public:
	int		currYx[2];	// current figure position
	int		destYx[2];	// new figure position
	string	littleFig = "I am the Figure";
};

class	Paw: public Figure
{
	public:
	string	littleFig = "I am the Paw";
};

#endif
