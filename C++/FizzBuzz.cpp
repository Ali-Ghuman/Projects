#include <iostream>
#define fizz 3
#define buzz 5
#define fizzbuzz 15

int main () 
{

  for (int i = 1; i <= 100; i++)  // if divisible by 3 output Fizz, if divisible by 5 output Buzz, if divisible by both 3 & 5 output FizzBuzz. 
  {
    if (!(i % fizzbuzz)) 
    {
      std::cout << "FizzBuzz\n"; 
    }
    else if (!(i % fizz)) 
    {
      std::cout << "Fizz\n"; 
    }
    else if (!(i % buzz)) 
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