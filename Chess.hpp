
#ifndef CHESS_HPP
#define CHESS_HPP

#include <iostream>
#include <string>
#include <map>

#include "Figure.hpp"

using std::string;
using std::cout;
using std::map;

class	Chess
{
	// private:
	public:
	map <string, string>	figsWhite;
	map <string, string>	figsBlack;
	char					board[8][8];

	Chess();
	void	figuresInit();
	void	boardInit();

	void	printBoard();

	void	moveBlack(string move);
	void	moveWhite(string move);
	
};

void	trim(std::string &s);
void	*ft_memset(void *s, int c, int n);

#endif
