
#include "../Chess.hpp"

bool	Chess::isBlackFigure(char figure)
{
	return (
	figure == BPAWN || figure == BBISHOP || figure == BKNIGHT
	|| figure == BROOK || figure == BQUEEN || figure == BKING
	);
}

bool	Chess::isWhiteFigure(char figure)
{
	return (
	figure == PAWN || figure == BISHOP || figure == KNIGHT
	|| figure == ROOK || figure == QUEEN || figure == KING
	);
}