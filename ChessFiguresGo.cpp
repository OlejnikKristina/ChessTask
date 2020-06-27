
#include "Chess.hpp"

bool	Chess::goFigure(Figure *figure)
{
	bool	isLegitMove;
	bool	isCheck;

	figure->initCoordinate(moveFrom, moveTo);
	isLegitMove = figure->checkMove(board);
	isCheck = figure->isCheckToKing(board);
	(color == white) ?
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
	if (king.checkMate(board))
		winner = color;
	return (isLegitMove);
}

bool Chess::goQueen(char current[3], char dest[3])
{
	Queen	queen(current, dest, color);
	bool	isLegitMove;
	bool	isCheck;

	queen.Rook::initCoordinate(moveFrom, moveTo);
	isLegitMove = queen.Rook::checkMove(board);
	if (isLegitMove == false)
		isLegitMove = queen.Bishop::checkMove(board);
	isCheck = queen.Rook::isCheckToKing(board);
	if (isCheck == false)
		isCheck = queen.Bishop::isCheckToKing(board);
	(color == white) ?
	(checkToBlack = isCheck) : (checkToWhite = isCheck);
	if (isLegitMove == false)
		std::cout << RED << " Illegal move for Queen."
		<< "Try again. \n" << RESET ;
	return (isLegitMove);
}
