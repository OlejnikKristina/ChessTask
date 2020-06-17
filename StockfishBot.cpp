
#include "StockfishBot.hpp"

void		StockfishBot::saveMove(const char moveFrom[3], const char moveTo[3])
{
	movesSet.append(moveFrom);
	movesSet.append(moveTo);
	movesSet.append(" ");
}

bool		StockfishBot::isBotActive()
{
	return (botActive);
}

void		StockfishBot::activateBot()
{
	botActive = true;
}

void		StockfishBot::setBotColor(char botColor)
{
	color = botColor;
}

char		StockfishBot::getBotColor()
{
	return (color);
}

bool		StockfishBot::sendRequest()
{
	std::ofstream	send; // File for IPC. Send moveSet to bot
	
	send.open(FILE_SEND);
	if (!send.is_open())
	{
		std::cout << RED << "Fail to open: " << FILE_SEND;
		exit(0);
		return (false);
	}
	send << movesSet << '\n' << "go\n";
	send.close();
	return (true);
}

std::string	StockfishBot::reciveAnsswer()
{
	std::ifstream	recive; // File for IPC. Recive move from bot
	std::string		ansswer;
	std::string		fullAnsswer;

	recive.open(FILE_RECIVE);
	if (!recive.is_open())
	{
		std::cout << RED << "Fail to open: " << FILE_RECIVE;
		exit(0);
		return (NULL);
	}
	while (getline(recive, ansswer))
	{
		fullAnsswer.append(ansswer);
	}
	fullAnsswer.append(ansswer);
	recive.close();
	return (fullAnsswer);
}

bool	StockfishBot::getBotMove(char move[])
{
	std::string		ansswer;
	size_t			pos;

	if (!sendRequest())
		return (false);
	system("./StockfishLinuxBot/stockfish <./saved_games/send.txt >./saved_games/recive.txt");
	ansswer = reciveAnsswer();
	if (!ansswer.length())
		return (false);
	pos = ansswer.find("bestmove ") + strlen("bestmove ");
	if (pos < 0)
		std::cout << RED << "Best move not found =(\n";
	ansswer = ansswer.substr(pos);
	strncpy(move, ansswer.c_str(), 5);
	return (true);
}

StockfishBot::StockfishBot()
{
	movesSet.append("position startpos moves ");
}

StockfishBot::~StockfishBot()
{}
