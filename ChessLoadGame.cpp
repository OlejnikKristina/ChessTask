
#include "Chess.hpp"


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

	key.resize(2);
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
		figures[key] = figs[11];
		figures.insert({key, figs[11]});
	}
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
