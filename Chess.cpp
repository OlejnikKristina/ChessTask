
#include "Chess.hpp"

void	Chess::playWithBot()
{
	std::string	colorToPlay;
	char		buff[2];

	colorToPlay[0] = '\0';
	while (bot.isBotActive() == false)
	{
		std::cout << CYAN << " Choose color to play:\n"
		<< WHITE << " [w]hite color\n [b]lack color:\n  ";
		std::cin >> colorToPlay;
		if (colorToPlay[0] == white)
		{
			bot.activateBot();
			bot.setBotColor(black);
		}
		else if (colorToPlay[0] == black)
		{
			bot.activateBot();
			bot.setBotColor(white);
		}
		else
			std::cout << RED << "Wrong option. Try again.\n";
	}
	std::cin.getline(buff, 2);
}

void	Chess::whoPlay()
{
	std::string option;
	char		buff[2];

	option[0] = '\0';
	while (option[0] == '\0')
	{
		std::cout << MAGENTA << " Choose option:\n" << WHITE
		<< " [1] Play with friend.\n [2] Play with bot.\n  ";
		std::cin >> option;
		if (option[0] == '2')
		{
			if (bot.isBotSrcExist() == false)
			{
				option[0] = '1';
				std::cout << YELLOW << " Chess Bot wasn't loaded. "
				<< "You can play only with a friend.\n";
			}
			else
				playWithBot();
		}
		if (option[0] == '1')
		{
			std::cin.getline(buff, 2);
			break ;
		}
		else if (option[0] != '2')
		{
			std::cout<<RED<<" Wrong option: " << option <<'\n'<< WHITE;
			option = '\0';
		}
	}
}

char	Chess::getWinner()
{
	if (winner == false)
		std::cout << GREEN << "  ** Game not finished yet  **\n";
	else if (winner == black)
		std::cout << GREEN << "  **  The winner is black!  **\n";
	else if (winner == white)
		std::cout << GREEN << "  **  The winner is white!  **\n";
	return (winner);
}

Chess::~Chess() {}

bool	Chess::readOption()
{
	char	option[42];
	bool	result;

	result = false;
	while (result == false)
	{
		std::cout << BLUE << "Type option: " << MAGENTA;
		std::cin.getline(option, 42);
		if(strcmp((const char *)option, "start game") == 0 ||
			strcmp((const char *)option, "restart game") == 0)
		{
			std::cout << "\n  ** Let's start the game!";
			figuresInit();
			boardInit();
			result = true;
		}
		else if(strcmp((const char *)option, "load game") == 0)
		{
			result = (loadGame()) ? true : false;
		}
		else if (strcmp((const char *)option, "exit") == 0)
		{
			std::cout << "Bye, bye!\n" << RESET;
			exit(0);
		}
		else if(strcmp((const char *)option, "save game") == 0)
		{
			std::cout <<  "Start the game, before save it.\n";
		}
		else
			std::cout << "Hint, type 'start game'\n";
		std::cout << RESET;
	}
	return (true);
}

void	Chess::boardPrint()
{
	std::cout << "\n     ._.._.._.._.._.._.._.._.\n";
	for (int y = 8; 0 < y; y--)
	{
		std::cout << "   " << MAGENTA << y << ' ' << WHITE;
		for (int x = 0; x < 8; x++)
		{
			std::cout << "|";
			if (board[y][x] == BKING)
				std::cout << YELLOW << '+';
			else if (isWhiteFigure(board[y][x]))
				std::cout << CYAN << board[y][x];
			else
			{
				std::cout << YELLOW << (char)toupper(board[y][x]);
				tolower(board[y][x]);
			}
			std::cout << WHITE << "|" ;
		}
		std::cout << std::endl;
	}
	std::cout << "    " << MAGENTA;
	for (int x = 0; x < 8; x++)
		std::cout << "  " << board[0][x];
	std::cout << RESET << "\n\n";
}

void	Chess::boardSetToZero()
{
	for (int y = 0; y <= 8; y++)
	{
		for (int x = 0; x < 8; x++)
			board[y][x] = ' ';
	}
}

void	Chess::boardInit()
{
	char	letter;

	letter = 'a';
	boardSetToZero();
	for (int x = 0; x < 8; x++)
	{
		board[0][x] = letter;	// Fill board by letters
		board[2][x] = PAWN;		// white and black pawns
		board[7][x] = BPAWN;
		letter++;
	}
	/* Init board by white figurs */
	board[1][A] = board[1][H] = ROOK;
	board[1][B] = board[1][G] = KNIGHT;
	board[1][C] = board[1][F] = BISHOP;
	board[1][D] = QUEEN;
	board[1][E] = KING;
	/* Init board by black figurs */
	board[8][A] = board[8][H] = BROOK;
	board[8][B] = board[8][G] = BKNIGHT;
	board[8][C] = board[8][F] = BBISHOP;
	board[8][D] = BQUEEN;
	board[8][E] = BKING;
}

void	Chess::figuresInit()
{
	string	letter;
	string	color = "color";

	figsWhite[color] = white;
	figsBlack[color] = black;
	for (char a = 'a'; a <= 'h'; a++)
	{
		letter = a;
		figsWhite[letter + "2"] = PAWN;
		figsBlack[letter + "7"] = BPAWN;
	}
	figsWhite["a1"] = figsWhite["h1"] = ROOK;
	figsWhite["b1"] = figsWhite["g1"] = KNIGHT;
	figsWhite["c1"] = figsWhite["f1"] = BISHOP;
	figsWhite["d1"] = QUEEN;
	figsWhite["e1"] = KING;
	figsBlack["a8"] = figsBlack["h8"] = BROOK;
	figsBlack["b8"] = figsBlack["g8"] = BKNIGHT;
	figsBlack["c8"] = figsBlack["f8"] = BBISHOP;
	figsBlack["d8"] = BQUEEN;
	figsBlack["e8"] = BKING;
}

void	Chess::startGame()
{
	gameRules();
	readOption();
	whoPlay();
	boardPrint();
	runGame();
}

Chess::Chess()
{
	winner = false;
	checkToBlack = false;
	checkToWhite = false;
}
