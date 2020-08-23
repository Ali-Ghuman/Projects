#include <iostream>

int main() 
{
  //This is the age of my dog
  int dog_age = 12; 
  int later_years, human_years; 
  int early_years = 21;     // dog's first 2 years are equivalent to 21 human years 

  later_years  = (dog_age - 2) * 4;  // calculating how a dog ages after first 2 years
  human_years = later_years + early_years; 

  std::cout << "My name is Max! Ruff ruff, I am " << human_years << " years old in human years\n"; 
}