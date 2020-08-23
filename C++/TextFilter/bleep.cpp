#include <iostream>
#include <string>
#include <ctype.h> 
#include "functions.hpp"
 int main() 
 {
  std::string word = "broccoli", text = "butt-Broccoli is an edible green plant in the cabbage family, whose large flowering head is used as a vegetable. The word broccoli comes from the Italian plural of '', which means the flowering crest of a cabbage, and is the diminutive form of brocco'', meaning small nail or sprout. Broccoli is often boiled or steamed but may be eaten raw. Broccoli is classified in the Italica cultivar group of the species Brassica oleracea. Broccoli has large flower heads, usually green in color, arranged in a tree-like structure on branches sprouting from a thick, edible stalk. The mass of flower heads is surrounded by leaves. Broccoli resembles cauliflower, which is a different cultivar group of the same species. Broccoli is a result of careful breeding of cultivated leafy cole crops in the Northern Mediterranean in about the 6th century BC. Since the Roman Empire, broccoli has been considered a uniquely valuable food among Italians. Broccoli was brought to England from Antwerp in the mid-18th century by Peter Scheemakers. Broccoli was first introduced to the United States by Italian immigrants but did not become widely known there until the 1920s."; 
  

  testbleep(word, text); 
  std::cout << text;

   return 0; 
 }