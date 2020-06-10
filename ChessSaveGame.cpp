
#include "Chess.hpp"

bool	Chess::isGameSaved(string gameFind)
{
	std::ifstream	gameList(GAME_LIST);
	std::string		gameName;

	if (!gameList)
	{
		std::cout << RED << "Can not oppen a file: "
		<< GAME_LIST << RESET <<'\n';
		return(false);
	}
	while (getline(gameList, gameName))
	{
		if (gameName == gameFind)
			return (true);
	}
	gameList.close();
	return (false);
}

bool	Chess::openLoadedGame(char gameName[], std::ifstream &loadedGame)
{
	loadedGame.open(gameName);
	if (!loadedGame)
	{
		std::cout << RED << "Can not oppen a file: "
		<< gameName << RESET <<'\n';
		return (false);
	}
	return (true);
}

void	Chess::loadBoard(std::ifstream &loadedGame)
{
	string	boardStr;

	getline(loadedGame, boardStr);
	for (int y = 0, i = 0; y < 9; y++)
	{
		for (int x = 0; x < 8; x++, i++)
		{
			board[y][x] = boardStr[i];
		}
	}
}

void	Chess::loadFigures(char gamePath[], std::ifstream &gameToLoad,
		map <string, char> &figures, char color)
{
	string		figs;
	string		key;
	string		nextFigureSet;
	string		colour = "color";
	char		val;

	figures[colour] = color;
	if (figures[colour] == 'w')
	{
		getline(gameToLoad, figs);
		nextFigureSet = "Black figures";
	}
	while (getline(gameToLoad, figs) && strcmp(figs.c_str(), nextFigureSet.c_str()) != 0)
	{
		key[0] = figs[4];
		key[1] = figs[5];
		key[2] = '\0';
		std::cout << figs << " key:" << key << " \n";
		val = figs[11];
		figures[key] = val;
		figures.insert({key, val});
	}
	show_figures(figures);
}

bool	Chess::loadGame()
{
	char			gameName[42];
	char			gamePath[42 + strlen(PATH)];
	std::ifstream	gameToLoad;

	showAvilableGames();
	std::cout << WHITE << "Enter saved game name: \n" << RESET;
	std::cin.getline(gameName, 42);
	while (isGameSaved(gameName) == false)
	{
		if (strcmp(gameName, "exit") == 0)
			exit(0);
		std::cout << WHITE << gameName << ". No such a game saved\n";
		std::cout << "Enter saved game name: " << YELLOW;
		std::cin.getline(gameName, 42);
	}
	std::cout << "Your game loaded: " << BLUE << gameName << '\n';
	strcpy(gamePath, PATH);
	strcpy(&gamePath[strlen(PATH)], (const char *)gameName);
	std::cout << "Game path: " << gamePath << '\n';
	if (!openLoadedGame(gamePath, gameToLoad))
		return (false);
	loadBoard(gameToLoad);
	loadFigures(gamePath, gameToLoad, figsWhite, 'w');
	loadFigures(gamePath, gameToLoad, figsBlack, 'b');
	gameToLoad.close();
	return (true);
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
