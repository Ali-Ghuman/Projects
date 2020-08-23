#include <iostream>


int main () 
{

  for (int i = 1; i <= 100; i++)  // if divisible by 3 output Fizz, if divisible by 5 output Buzz, if divisible by both 3 & 5 output FizzBuzz. 
  {
    if ( i % 3 == 0 && i % 5 == 0) 
    {
      std::cout << "FizzBuzz\n"; 
    }
    else if ( i % 3 == 0) 
    {
      std::cout << "Fizz\n"; 
    }
    else if ( i % 5 == 0) 
    {
      std::cout << "Buzz\n"; 
    } 
    else 
    {
      std::cout << i << "\n";
    }
  }

  return 0; 
}