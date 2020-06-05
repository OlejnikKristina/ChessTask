# ♕♔ Console Chess

With console chess application players can compete in chess directly in the console.
<br>
The program validates all legit chess moves (if a player wants to make a move that is not allowed by
chess rules, the application must block such attempt and show corresponding notification).<br>
Technical requirements / limitations: Programming language: C++. External libraries: STL only
<br>
Now you can play with your friends in chess game from your console! Even Garry Kasparov would love to try it out. Enjoy.<br>
<br><img alt="portfolio_view" src="https://github.com/OlejnikKristina/Filler-Visualization/blob/master/img/chess_giff.gif" style ="margin-left: 100px;">
## ♙Installation
Console Chess is configured to be build with make tool. You can find Makefile in the root of the repository. To launch Console Chess follow next commands:
`make`<br>

## ♖Usage
After building is finished, you can launch the program by simply typing: `./Chess` <br>
The program will show to you hints how to play in this amaizing game. <br>
After launching program type: `start game`. <br>
Enter moves in format [figure current postion][firgure destination position] <br>
Example: `e2 e4` will move white pawn on two spots up. <br>
<br><img width="600" alt="portfolio_view" src="https://github.com/OlejnikKristina/Filler-Visualization/blob/master/img/Chess1.bmp" style ="margin-left: 100px;"><br>

### Convention
The chess figure in current game are representet by letters in following format: <br>
♟P - Pawn <br>
♞K - Knight <br>
♝B - Bishop <br>
♜R - Rook <br>
♛Q - Queen <br>
♚K - King<br>

### Environment
WSL Ubuntu

## Bugs
Please open an 'issues' if you find any bugs.
