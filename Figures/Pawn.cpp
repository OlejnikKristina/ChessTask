
#include "Pawn.hpp"
#include "Figure.hpp"

Pawn::Pawn(){}

Pawn::Pawn(char current[3], char dest[3], char fcolor)
	:Figure(current, dest, fcolor)
{
	std::cout << "I am pawn! [" << currPos << "] [" << destPos << "] ";
}
