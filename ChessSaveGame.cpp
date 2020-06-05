
#include "Chess.hpp"

bool	Chess::isGameSaved(string gameFind)
{
	std::ifstream	gameList(GAME_LIST);
	std::string		gameName;

	while (getline(gameList, gameName))
	{
		if (gameName == gameFind)
			return (true);
	}
	gameList.close();
	return (false);
}

bool	Chess::loadGame()
{
	char	gameName[42];

	showAvilableGames();
	std::cout << WHITE << "Enter saved game name: \n" << RESET;
	std::cin.getline(gameName, 42);
	while (isGameSaved(gameName) == false)
	{
		std::cout << WHITE << gameName << ". No such a game saved\n";
		std::cout << "Enter saved game name: " << YELLOW;
		std::cin.getline(gameName, 42);
	}
	std::cout << "Saved game: " << BLUE << gameName << '\n';
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

	gameList << gameToSave << '\n';
	saveFigures(&newGameFile, figsWhite);
	newGameFile << "Black figures\n";
	saveFigures(&newGameFile, figsBlack);
	newGameFile << "Chess board\n";
	newGameFile.write((char *)board, 8*9);
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
