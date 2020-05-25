
#include "Chess.hpp"

void	Chess::figuresInit()
{
	string	letter;

	figsWhite["сolour"] = "white";
	figsBlack["colour"] = "black";
	for (char a = 'a'; a <= 'h'; a++)
	{
		letter = a;
		figsWhite[letter + "2"] = PAWN;
		figsBlack[letter + "7"] = PAWN;
	}
	figsWhite["a1"] = figsBlack["a8"] = ROOK;
	figsWhite["h1"] = figsBlack["h8"] = ROOK;
	figsWhite["b1"] = figsBlack["b8"] = KNIGHT;
	figsWhite["g1"] = figsBlack["g8"] = KNIGHT;
	figsWhite["c1"] = figsBlack["c8"] = BISHOP;
	figsWhite["f1"] = figsBlack["f8"] = BISHOP;
	figsWhite["d1"] = figsBlack["d8"] = QUEEN;
	figsWhite["e1"] = figsBlack["e8"] = KING;
}

Chess::Chess()
{
	ft_memset((void *)&board, '\0', sizeof(char) * 16);
	figuresInit();
}

int		main()
{
	Chess game;

	return (0);
}