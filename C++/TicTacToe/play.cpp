#include <iostream>
#include <vector> 
#include "play.hpp"

void greet(void) 
{
  std::cout << "Welcome to Tic-Tac-Toe. First to get three in a row wins!\n"; 
}

void game_board(std::vector<char> choose) // places the vectors in the appropriate location for swapping it out with x's and o's. Numbers are originally shown to mark the squares.
{
  std::cout << " " << choose[0] << "  | " << choose[1] << "  | " << choose[2] << "  \n";
  std::cout << "____|____|____\n";
  std::cout << " " << choose[3] << "  | " << choose[4] << "  | " << choose[5] << "  \n";
  std::cout << "____|____|____\n";
  std::cout << " " << choose[6] << "  | " << choose[7] << "  | " << choose[8] << "  \n";
  std::cout << "    |    |    \n";
}

int win(std::vector<char> choose) // checks the conditions for all 8 win possibilities. Returns a 1 if one of the users wins. 
{
  if (choose[0] == 'X' && choose[1] == 'X' && choose[2] == 'X' 
   || choose[3] == 'X' && choose[4] == 'X' && choose[5] == 'X' 
   || choose[6] == 'X' && choose[7] == 'X' && choose[8] == 'X'
   || choose[0] == 'X' && choose[3] == 'X' && choose[6] == 'X' 
   || choose[1] == 'X' && choose[4] == 'X' && choose[7] == 'X' 
   || choose[2] == 'X' && choose[5] == 'X' && choose[8] == 'X' 
   || choose[0] == 'X' && choose[4] == 'X' && choose[8] == 'X' 
   || choose[2] == 'X' && choose[4] == 'X' && choose[6] == 'X')
  {
    game_board(choose);
    std::cout << "X wins!\n";
    return 1;

  } 
  if (choose[0] == 'O' && choose[1] == 'O' && choose[2] == 'O' 
   || choose[3] == 'O' && choose[4] == 'O' && choose[5] == 'O' 
   || choose[0] == 'O' && choose[3] == 'O' && choose[6] == 'O' 
   || choose[1] == 'O' && choose[4] == 'O' && choose[7] == 'O' 
   || choose[2] == 'O' && choose[5] == 'O' && choose[8] == 'O' 
   || choose[0] == 'O' && choose[4] == 'O' && choose[8] == 'O' 
   || choose[2] == 'O' && choose[4] == 'O' && choose[6] == 'O') 
  {
    game_board(choose);
    std::cout << "O wins!\n";
    return 1; 
  } 
}
