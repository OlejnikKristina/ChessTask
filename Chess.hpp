
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
	public:
	char	getWinner();
	Chess();
	~Chess();

	private:
	char				board[9][8];
	char				currPos[3];
	char				destPos[3];
	char				color;
	bool				checkToWhite;
	bool				checkToBlack;
	char				winner;
	map <string, char>	figsWhite;
	map <string, char>	figsBlack;
	int					moveFrom[2];
	int					moveTo[2];

	void	figuresInit();
	void	boardInit();
	void	boardSetToZero();
	void	boardPrint();
	bool	runGame();
	bool	getMove();
	bool	substructMove(char move[], char direction[3]);
	bool	moveFigure(map <string, char> &figures);
	void	updateFigureSpot(std::map <string, char> &figures);
	void	show_figures(std::map <string, char> figures);
	bool	putFigureOnBoard(char color, \
			std::map <string, char> &figures);
	bool	isBlackFigure(char figure);
	void	gameRules();
	bool	goPawn(char current[3], char dest[3]);
	bool	goRook(char current[3], char dest[3]);
	bool	goBishop(char current[3], char dest[3]);
	bool	goKnight(char current[3], char dest[3]);
	bool	goKing(char current[3], char dest[3]);
	bool	goQueen(char current[3], char dest[3]);
	bool	isWhiteFigure(char figure);
};

/*	figsWhite[key][val], figsBlack [key][val]
	key = current figure position on a board (a2, b7 ...);
	val = figure
*/

void	trim(std::string &s);
void	*ft_memset(void *s, int c, int n);

#endif
