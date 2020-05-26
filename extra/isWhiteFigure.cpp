
#include "Chess.hpp"

bool	Chess::isWhiteFigure(char figure)
{
	return (isupper(figure) || figure == KING);
}
