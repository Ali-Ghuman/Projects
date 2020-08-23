#include <iostream>

int main() 
{
  double year; 

  std::cout << "Enter a year: "; 
  std::cin >> year; 
  
  //checks if the year entered is valid
  if ((year/1000) < 1 || (year/1000) >= 10) 
  {
    std::cout << "Invalid\n";
    return 0; 
  }

  //checks the coditions for leap years 
  if ((int) year % 4 == 0) 
  {
    if ((int)year % 100 == 0) 
    {
      if ((int) year % 400 != 0) 
      {
        std::cout << "Not a leap year\n"; 
      } 
      else 
      {
        std::cout << "It is a leap year\n";
      }
    } 
    else 
    {
      std::cout << "It is a leap year\n"; 
    }
  } 
  else 
    {
      std::cout << "Not a leap year\n"; 
      return 0; 
    }
    
}