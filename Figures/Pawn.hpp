
#ifndef PAWN_HPP
#define PAWN_HPP

#include "Figure.hpp"

class		Pawn: public Figure
{
	public:
	Pawn();
	Pawn(char current[3], char dest[3], char color);
	bool		chekMove(char board[9][8]);
	bool		checkMoveWhitePawn(char board[9][8]);
	bool		checkMoveBlackPawn(char board[9][8]);
};

#endif