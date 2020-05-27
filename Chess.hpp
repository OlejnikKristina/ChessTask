
#ifndef CHESS_HPP
#define CHESS_HPP

#include <iostream>
#include <string>
#include <map>
#include <ctype.h>

#include "Figure.hpp"
#include "shortcuts.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"

using std::string;
using std::cout;
using std::map;

class	Chess
{
	private:
	char					currPos[3];
	char					destPos[3];
	int						moveFrom[2];
	int						moveTo[2];

	public:
	map <string, char>		figsWhite;
	map <string, char>		figsBlack;
	char					board[9][8];

	Chess();
	void	figuresInit();
	void	boardInit();
	void	boardPrint();

	bool	runGame();
	bool	getMove();
	bool	substructMove(char move[], char direction[3]);
	bool	moveFigure(map <string, char> figures);
	bool	putFigureOnBoard(char color);
	bool	isBlackFigure(char figure);
	bool	putWhiteFigure();
	bool	putBlackFigure();

	void	gameRules();

	/* Additional functions */
	bool		isWhiteFigure(char figure);
	
};

/*	figsWhite[key][val], figsBlack [key][val]
	key = current figure position on a board (a2, b7 ...);
	val = figure
*/

void	trim(std::string &s);
void	*ft_memset(void *s, int c, int n);

#endif
