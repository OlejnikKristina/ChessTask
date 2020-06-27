
#ifndef STOCKFISHBOT_HPP
#define STOCKFISHBOT_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctype.h>
#include <string>
#include "shortcuts.hpp"

#define CHESS_AI_PATH "./StockfishLinuxBot/stockfish"
#define FILE_SEND "./saved_games/send.txt"
#define FILE_RECIVE "./saved_games/recive.txt"

class	StockfishBot
{
	protected:
	std::string		movesSet;
	bool			botActive;

	public:
	char			color;
	public:
	StockfishBot();
	~StockfishBot();
	void			saveMove(const char moveFrom[3], const char moveTo[3]);
	bool			isBotActive();
	void			activateBot();
	void			setBotColor(char botColor);
	char			getBotColor();
	bool			getBotMove(char move[]);
	bool			sendRequest();
	bool			isBotSrcExist();
	std::string		reciveAnsswer();
};

#endif
