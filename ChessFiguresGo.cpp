
#include "Chess.hpp"

bool Chess::goPawn(char current[3], char dest[3], char color)
{
	Pawn pawn(current, dest, color);

	pawn.initCoordinate(moveFrom, moveTo);
	return (pawn.checkMove(board));
}

bool Chess::goRook(char current[3], char dest[3], char color)
{
	Rook rook(current, dest, color);

	rook.initCoordinate(moveFrom, moveTo);
	return (rook.checkMove(board));
}

bool Chess::goBishop(char current[3], char dest[3], char color)
{
	Bishop bishop(current, dest, color);

	bishop.initCoordinate(moveFrom, moveTo);
	return (bishop.checkMove(board));
}

bool Chess::goKnight(char current[3], char dest[3], char color)
{
	Knight knight(current, dest, color);

	knight.initCoordinate(moveFrom, moveTo);
	return (knight.checkMove(board));
}

bool Chess::goKing(char current[3], char dest[3], char color)
{
	King king(current, dest, color);

	king.initCoordinate(moveFrom, moveTo);
	return (king.checkMove(board));
}

bool Chess::goQueen(char current[3], char dest[3], char color)
{
	Queen queen(current, dest, color);

	queen.Rook::initCoordinate(moveFrom, moveTo);
	if (queen.Rook::checkMove(board))
		return (true);
	else if (queen.Bishop::checkMove(board))
		return (true);
	return (false);
}
