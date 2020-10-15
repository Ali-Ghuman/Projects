#include <iostream>
#include <string> 
#include "functions.hpp"

void testbleep(std::string &word, std::string &text) //tests to see if the word under scrutiny matches a position in text 
{
  for (int i = 0; i < text.size(); i++) 
  {
    int count = 0; 
      for (int j = 0; j < word.size(); j++)
      {
        if (word[j] == text[i] || toupper(word[j]) == text[i])
        {
         count++;   
         i++; 
        }
        else 
        {
          continue; 
        }
    }
    if (count == word.size()) 
    {
      bleep(word, text, i); 
    }
  }
}

void bleep(std::string &word, std::string &text, int i)
{ 
  for (int k = 0; k < word.size(); k++) 
      {
        text[i - word.size() + k] = '*'; 
      } 
  while (text[i] != ' ')  
    {
      if (!( 'a' <= text[i] <= 'z' || 'A' <= text[i] <= 'Z')) 
      {
        break; 
      }
      text[i] = '*';
      i++; 
    }  
}