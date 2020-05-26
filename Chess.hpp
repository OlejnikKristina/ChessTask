
#ifndef CHESS_HPP
#define CHESS_HPP

#include <iostream>
#include <string>
#include <map>
#include <ctype.h>

#include "Figure.hpp"
#include "shortcuts.hpp"

using std::string;
using std::cout;
using std::map;

class	Chess
{
	// private:
	public:
	map <string, string>	figsWhite;
	map <string, string>	figsBlack;
	char					board[9][8];

	Chess();
	void	figuresInit();
	void	boardInit();

	void	boardPrint();

	void	moveBlack(string move);
	void	moveWhite(string move);
	/* Additional functions */
	bool		isWhiteFigure(char figure);
	
};

void	trim(std::string &s);
void	*ft_memset(void *s, int c, int n);

#endif
