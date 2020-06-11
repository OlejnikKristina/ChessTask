
#ifndef CHESS_HPP
#define CHESS_HPP

#include <iostream>
#include <string>
#include <map>
#include <ctype.h>
#include <fstream>

#include "./Figures/Figure.hpp"
#include "shortcuts.hpp"
#include "./Figures/Queen.hpp"
#include "./Figures/King.hpp"
#include "./Figures/Rook.hpp"
#include "./Figures/Bishop.hpp"
#include "./Figures/Knight.hpp"
#include "./Figures/Pawn.hpp"

#define PATH "./saved_games/"
#define GAME_LIST "./saved_games/games_list.txt"

using std::string;
using std::map;

class	Chess
{
	public:
	bool	runGame();
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
	bool	getMove();
	bool	saveGame();
	bool	readOption();
	bool	substructMove(char move[], char direction[3]);
	bool	moveFigure(map <string, char> &figures);
	void	updateFigureSpot(std::map <string, char> &figures);
	void	show_figures(std::map <string, char> figures);
	bool	putFigureOnBoard(char color, std::map <string, char> &figures);
	bool	isBlackFigure(char figure);
	void	gameRules();
	bool	goFigure(Figure *figure);
	bool	goKing(char current[3], char dest[3]);
	bool	goQueen(char current[3], char dest[3]);
	bool	isWhiteFigure(char figure);
/*	**		Save game	**	*/
	void	addGameToList(string gameToSave);
	void	saveFigures(std::ofstream *newGameFile, map <string, char> figures);
	void	showAvilableGames();
	bool	isGameSaved(string gameName);
	bool	openLoadedGame(char gameName[], std::ifstream &loadeGame);
	void	loadBoard(std::ifstream &loadedGame);
	void	loadFigures(char gamePath[], std::ifstream &gameToLoad,\
			map <string, char> &figures, char color);
	bool	loadGame();
};

/*	figsWhite[key][val], figsBlack [key][val]
	key = current figure position on a board (a2, b7 ...);
	val = figure
*/

void	trim(std::string &s);
void	*ft_memset(void *s, int c, int n);

#endif
