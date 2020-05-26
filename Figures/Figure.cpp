
#include "Figure.hpp"

Figure::Figure() {}

Figure::Figure(char current[3], char dest[3])
{
	strncpy(currPos, (const char *)current, 3);
	strncpy(destPos, (const char *)dest, 3);
	currPos[2] = '\0';
	destPos[2] = '\0';
	std::cout << "Fig pos: " << currPos << '\n';
}
 