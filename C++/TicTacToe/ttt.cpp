#include <iostream> 
#include <vector> 
#include "play.hpp" 

int main(void) 
{
  std::vector<char> choose = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // sets up vectors that align with the board
  int tie = 0, choice; 
  bool symbol = true; 
  greet();


  while(tie < 9) // after 9 turns, the board will be filled and it will be a tie
  {
    if (tie > 0) 
    {
    std::cout << "\n\n\n"; 
    }

    game_board(choose);

    std::cout << "Type a number: "; 
    std::cin >> choice;

    if (symbol == true) //selects x first and then alternates to x and o. Increments tie.  
    { 
      if (choose[choice-1] == 'X' || choose[choice-1] == 'O')
      {
        std::cout << "This spot's taken!\n";
      } 
      else 
      { 
      choose[choice-1] = 'X';
      symbol = false;
      tie++;
      }  
    } 
    else 
    {
      if (choose[choice-1] == 'O' || choose[choice-1] == 'X')
      {
        std::cout << "This spot's taken!\n";
      } 
      else 
      {
      choose[choice-1] = 'O';
      symbol = true;
      tie++;  
      }  
    }  
    
  win(choose);
    if (win(choose) == 1) // if the function returns a 1, the game has ended with one of the players winning. Otherwise, it is be a tie. 
    {
      return 0; 
    } 
 }
  std::cout << "It's a tie!\n";
}