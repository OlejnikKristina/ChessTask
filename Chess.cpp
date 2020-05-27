
#include "Chess.hpp"

void	Chess::boardPrint()
{
	std::cout << '\n';
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

void	Chess::boardInit()
{
	char	letter;

	letter = 'a';
	ft_memset((void *)&board, '\0', 9 * 8);
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
	board[4][C] = BISHOP;
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
	map <string, char> ::iterator it;

	figsWhite[color] = 'w';
	figsBlack[color] = 'b';
	for (char a = 'a'; a <= 'h'; a++)
	{
		letter = a;
		figsWhite[letter + "2"] = PAWN;
		figsBlack[letter + "7"] = BPAWN;
	}
	figsWhite["a1"] = figsWhite["h1"] = ROOK;
	figsWhite["c4"] = BISHOP;		// TEST
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

Chess::Chess()
{
	gameRules();
	figuresInit();
	boardInit();
	boardPrint();
	runGame();
}

int		main()
{
	Chess game;

	return (0);
}