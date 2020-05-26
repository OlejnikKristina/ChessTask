
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
	private:
	char					moveFrom[3];
	char					moveTo[3];

	public:
	map <string, string>	figsWhite;
	map <string, string>	figsBlack;
	char					board[9][8];

	Chess();
	void	figuresInit();
	void	boardInit();
	void	boardPrint();

	bool	runGame();
	bool	getMove();
	bool	substructMove(char move[], char direction[3]);
	bool	checkCurrSpot(map <string, string> figures);
	bool	checkMove(map <string, string> figures);
	void	moveBlack(string move);
	void	moveWhite(string move);

	void	gameRules();

	/* Additional functions */
	bool		isWhiteFigure(char figure);
	
};

void	trim(std::string &s);
void	*ft_memset(void *s, int c, int n);

#endif
