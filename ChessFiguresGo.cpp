
#include "Chess.hpp"

bool Chess::goPawn(char current[3], char dest[3])
{
	Pawn	pawn(current, dest, color);
	bool	isLegitMove;
	bool	isCheck;

	pawn.initCoordinate(moveFrom, moveTo);
	isLegitMove = pawn.checkMove(board);
	if (isCheck = pawn.isCheckToKing(board))
		std::cout << "Check from pawn what a shame!";
	(color == 'w') ?
	(checkToBlack = isCheck) : (checkToWhite = isCheck);
	return (isLegitMove);
}

bool Chess::goRook(char current[3], char dest[3])
{
	Rook	rook(current, dest, color);
	bool	isLegitMove;
	bool	isCheck;

	rook.initCoordinate(moveFrom, moveTo);
	isLegitMove = rook.checkMove(board);
	isCheck = rook.isCheckToKing(board);
	(color == 'w') ?
	(checkToBlack = isCheck) :
	(checkToWhite = isCheck);
	return (isLegitMove);
}

bool Chess::goBishop(char current[3], char dest[3])
{
	Bishop	bishop(current, dest, color);
	bool	isLegitMove;
	bool	isCheck;

	bishop.initCoordinate(moveFrom, moveTo);
	isLegitMove = bishop.checkMove(board);
	isCheck = bishop.isCheckToKing(board);
	(color == 'w') ?
	(checkToBlack = isCheck) :
	(checkToWhite = isCheck);
	return (isLegitMove);
}

bool Chess::goKnight(char current[3], char dest[3])
{
	Knight	knight(current, dest, color);
	bool	isLegitMove;
	bool	isCheck;

	knight.initCoordinate(moveFrom, moveTo);
	isLegitMove = knight.checkMove(board);
	isCheck = knight.isCheckToKing(board);
	(color == 'w') ?
	(checkToBlack = isCheck) :
	(checkToWhite = isCheck);
	return (isLegitMove);
}

bool Chess::goKing(char current[3], char dest[3])
{
	King	king(current, dest, color);
	bool	isLegitMove;

	king.initCoordinate(moveFrom, moveTo);
	isLegitMove = king.checkMove(board);
	return (isLegitMove);
}

bool Chess::goQueen(char current[3], char dest[3])
{
	Queen	queen(current, dest, color);
	bool	isLegitMove;
	bool	isCheck;

	queen.Rook::initCoordinate(moveFrom, moveTo);
	if (isLegitMove = queen.Rook::checkMove(board))
		isCheck = queen.Rook::isCheckToKing(board);
	else
	{
		isLegitMove = queen.Bishop::checkMove(board);
		isCheck = queen.Bishop::isCheckToKing(board);
	}
	(color == 'w') ?
	(checkToBlack = isCheck) : (checkToWhite = isCheck);
	return (isLegitMove);
}
