
#include "Pawn.hpp"
#include "Figure.hpp"

Pawn::Pawn(){}

Pawn::Pawn(char current[3], char dest[3])
	:Figure(current, dest)
{
	std::cout << "I am pawn! [" << currPos << "] [" << destPos << "] ";
}
