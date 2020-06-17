
#include "Chess.hpp"

bool	Chess::isGameSaved(string gameFind)
{
	std::ifstream	gameList(GAME_LIST);
	std::ifstream	savedGame;
	std::string		gameName;
	bool			returnVal;

	if (!gameList)
	{
		std::cout << RED << "Can not oppen a file: "
		<< GAME_LIST << RESET <<'\n';
		return(false);
	}
	while (getline(gameList, gameName))
	{
		if (gameName == gameFind)
		{
			savedGame.open(PATH + gameName);
			returnVal = (savedGame) ? (true) : (false);
			break ;
		}
	}
	gameList.close();
	savedGame.close();
	return (returnVal);
}

void	Chess::showAvilableGames()
{
	std::ifstream	gameList(GAME_LIST);
	string			gameName;
	int				i;

	i = 1;
	if (!gameList)
	{
		std::cout << "There are not any saved game yet\n";
		return ;
	}
	std::cout << CYAN << "  **   Choose game to load   **" << WHITE;
	std::cout << '\n';
	while (getline(gameList, gameName))
	{
		std::cout << " #" << i << "    " << YELLOW 
		<< gameName << WHITE << '\n';
		i++;
	}
	std::cout << RESET;
	gameList.close();
}

void	Chess::saveFigures(std::ofstream *newGameFile, map <string, char> figures)
{
	map <string, char>::iterator it;

	it = figures.begin();
	while (it != figures.end())
	{
		newGameFile->write("key[", 4);
		newGameFile->write(it->first.c_str(), 2);
		newGameFile->write("]val[", 5);
		newGameFile->write((char *)&(it->second), 1);
		newGameFile->write("]\n", 2);
		it++;
	}
}

void	Chess::addGameToList(string gameToSave)
{
	string			gamePath = PATH + gameToSave;
	std::ofstream	gameList(GAME_LIST, std::ios::app);
	std::ofstream	newGameFile(gamePath, std::ios::app);

	if (!gameList || !newGameFile)
	{
		std::cout << RED << "Error can't open a";
	}
	newGameFile.write((char *)board, 8 * 9);
	newGameFile << "\nWhite figures\n";
	gameList << gameToSave << '\n';
	saveFigures(&newGameFile, figsWhite);
	newGameFile << "Black figures\n";
	saveFigures(&newGameFile, figsBlack);
	gameList.close();
	newGameFile.close();
}

bool	Chess::saveGame()
{
	char	gameName[42];

	std::cout << "Enter the name of game to save: ";
	std::cin.getline(gameName, 42);
	while (isGameSaved(gameName))
	{
		std::cout << "This game already saved. Choose other name: ";
		std::cin.getline(gameName, 42);
	}
	addGameToList(gameName);
	std::cout << WHITE << "Game successfully saved\n" << RESET;
	return (false);
}
