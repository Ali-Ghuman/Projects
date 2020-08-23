#include <iostream>
#include <vector> 
#include <time.h> 
#include "ufo_functions.hpp"

int main() 
{
  bool quit = false;  
  srand(time(NULL)); 


  while (!quit) 
  {
    int select = rand() % 10;
    std::vector<std::string> vec_codeword = {"youtube", "nose", "wassup","dinosaurs", "chocolate", "pumpkin", "salutations", "janitor", "engineer", "attorney", "ankle", "google"}; 
    std::string codeword = vec_codeword[select];  //sets codeword to a random word from vec_codeword
    std::string answer= "";
    
    for (int i = 0; i < codeword.size(); i++) // sets answer to equal the number of characters in the codeword 
    {
      answer += '_'; 
    } 

    int misses = 0; 
    std::vector<char> incorrect; 
    bool guess = false; 
    char letter, again; 
    
    greet(); 
    hint(select); //selects hint based off the random number. 

    while (answer != codeword && misses < 7)  // if user doesn't get the codeword in 7 tries, they lose
    {
      display_misses(misses); 
      display_status(incorrect, answer);
      std::cout << "\nPlease enter your guess: ";
      std::cin >> letter; 
      letter = tolower(letter); 

      for (int i = 0; i < codeword.size(); i++) 
      {
        if (letter == codeword[i]) 
        {
          answer[i] = letter; 
          guess = true; 
        }
      } 
        if (guess) 
        {
          std::cout << "\nCorrect!\n"; 
        } 
        else 
        {
          std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
          incorrect.push_back(letter);  
          misses++;
        }
        guess = false; 
    } 
    
    end_game(answer, codeword);
    
    std::cout << "\nPlay again? (y/n)\n"; 
    std::cin >> again;
    if (again == 'n' || again == 'N' )   // if they select no, the while loop quits and the game ends.  
    {
      quit = true;    
    }   

  }
}
