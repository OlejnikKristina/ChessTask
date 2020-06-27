
#ifndef CHESS_HPP
#define CHESS_HPP

#include <iostream>
#include <gtest/gtest_prod.h>
#include <fstream>
#include <ctype.h>
#include <string>
#include <map>

#include "./Figures/Figure.hpp"
#include "./Figures/Queen.hpp"
#include "./Figures/King.hpp"
#include "./Figures/Rook.hpp"
#include "./Figures/Bishop.hpp"
#include "./Figures/Knight.hpp"
#include "./Figures/Pawn.hpp"
#include "StockfishBot.hpp"
#include "shortcuts.hpp"

#define PATH "./saved_games/"
#define GAME_LIST "./saved_games/games_list.txt"

using std::string;
using std::map;

class	StockfishBot;


class	Chess
{
	public:
	void	startGame();
	char	getWinner();
	Chess();
	~Chess();

	protected:
	enum				colour {white = 'w', black = 'b'};
	char				board[9][8];	// Chess board (first line represent letters on a board)
	char				currPos[3];		// Current figure position
	char				destPos[3];		// Destination position
	int					moveFrom[2];	// The same as 'currPos' only in integer
	int					moveTo[2];		// The same as 'destPos' only in integer
	char				color;			// Color of current player who make move
	bool				checkToWhite;	// Detect if there are check to White palyer
	bool				checkToBlack;	// Detect if there are check to Black palyer
	char				winner;			// Here we store winner obviously
	map <string, char>	figsWhite;		// Set of figures in format: figsWhite[key][val]
	map <string, char>	figsBlack;		// key=current figure pos; val=figure; exmpl:figsWhite[e2]=PAWN
										// Detect if we play with bot.'w'==white bot;'b'==black bot
	StockfishBot		bot;

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
	void	runGame();
	bool	goFigure(Figure *figure);
	bool	goKing(char current[3], char dest[3]);
	bool	goQueen(char current[3], char dest[3]);
	bool	isWhiteFigure(char figure);
/**			Save game		**/
	void	addGameToList(string gameToSave);
	void	saveFigures(std::ofstream *newGameFile, map <string, char> figures);
	void	showAvilableGames();
	bool	isGameSaved(string gameName);
	bool	openLoadedGame(char gameName[], std::ifstream &loadeGame);
	void	loadBoard(std::ifstream &loadedGame);
	void	loadFigures(char gamePath[], std::ifstream &gameToLoad,\
			map <string, char> &figures, char color);
	bool	loadGame();
/**			Chess Bot		**/
	void	whoPlay();
	void	playWithBot();

	friend class Test;
	friend class ChessTest;
	FRIEND_TEST(ChessTest, FirstMoveWhite_FromPawnA2ToPawnH2);
};

void	trim(std::string &s);
void	*ft_memset(void *s, int c, int n);

#endif
