#include <iostream>
#define fizz 3
#define buzz 5
#define fizzbuzz 15

int main () 
{

  for (int i = 1; i <= 100; i++)  // if divisible by 3 output Fizz, if divisible by 5 output Buzz, if divisible by both 3 & 5 output FizzBuzz. 
  {
    std::string output = "";
    if (!(i % fizz)) 
    {
       output += "Fizz"; 
    }
    if (!(i % buzz)) 
    {
       output += "Buzz"; 
    }
    if (output == "") {std::cout << i << "\n";}
    else {std::cout << output << "\n";}
  }

  return 0; 
}