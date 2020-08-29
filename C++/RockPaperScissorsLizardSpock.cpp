// This program will emulate rock paper scissors, b/w the user and computer. Can also be done with nested switch statements. 

#include <iostream> 
#include <stdlib.h> 

int main() {

srand(time(NULL)); 
int computer = rand() % 3 + 1;
int user = 0; 

std::cout << "Rock Paper Scissors Lizard Spock!\n\n";
std::cout << "1) ✊\n";
std::cout << "2) ✋\n";
std::cout << "3) ✌️\n";
std::cout << "4) 🖖\n";
std::cout << "5) 🦎\n";

std::cout << "shoot! ";
std::cin >> user; 
// tests if input is valid
if (user < 1 || user > 5) 
{
  std::cout << "Invalid\n";
}
if (user == computer) 
{
  std::cout << "It's a tie!\n"; 
} 

//goes through all the variations of user vs computer
if (user == 1) 
{
  if (computer == 2) 
  {
    std::cout << "Paper : You Lose!\n"; 
  } 
  else if (computer == 3)
  {
    std::cout << "Scissors: You Win!\n"; 
  } 
  else if ( computer == 4) 
  {
    std::cout << "Spock : You Lose!\n"; 
  } 
  else if (computer == 5) 
  {
    std::cout << "Lizard : You Win!\n"; 
  }
}

if (user == 2) 
{
  if (computer == 3) 
  {
    std::cout << "Scissors: You Lose!\n"; 
  } 
  else if (computer == 1)
  {
    std::cout << "Rock: You Win!\n"; 
  } 
  else if ( computer == 4) 
  {
    std::cout << "Spock : You Win!\n"; 
  } 
  else if (computer == 5) 
  {
    std::cout << "Lizard : You Lose!\n"; 
  }
}


if (user == 3) 
{
  if (computer == 1) 
  {
    std::cout << "Rock: You Lose!\n"; 
  } 
  else if (computer == 2)
  {
    std::cout << "Paper: You Win!\n"; 
  }
  else if ( computer == 4) 
  {
    std::cout << "Spock : You Lose!\n"; 
  } 
  else if (computer == 5) 
  {
    std::cout << "Lizard : You Win!\n"; 
  }
}

if (user == 4) 
{
  if (computer == 1) 
  {
    std::cout << "Rock: You Win!\n"; 
  } 
  else if (computer == 2)
  {
    std::cout << "Paper: You Lose!\n";  
  } 
  else if (computer == 5) 
  {
    std::cout << "Lizard : You Lose!\n"; 
  } 
  else if (computer == 3) 
  {

    std::cout << "Scissors : You Win!\n"; 
  }
}

if (user == 5) 
{
  if (computer == 1) 
  {
    std::cout << "Rock: You Lose!\n"; 
  } 
  else if (computer == 2)
  {
    std::cout << "Paper: You Win!\n";  
  } 
  else if (computer == 4) 
  {
    std::cout << "Spock : You Win!\n"; 
  } 
  else if (computer == 3) 
  {
    std::cout << "Scissors : You Lose!\n"; 
  } 
}

  return 0; 
}