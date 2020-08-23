// a quiz that takes user answers and gives points to respective houses and finally caclculates which house has the most points. If there is a tie, order of precedence takes place.
#include <iostream> 

int main() {
  int gryffindor = 0, hufflepuff = 0, ravenclaw = 0, slytherin = 0, max = 0;    
  int answer1, answer2, answer3, answer4; 
  std::string house; 
 

  std::cout << "The Sorting Hat Quiz!\n";

  std::cout << "Q1) When I'm dead, I want people to remember me as: \n\n";
  std::cout << "   1) The Good\n";
  std::cout << "   2) The Great\n";
  std::cout << "   3) The Wise\n";
  std::cout << "   4) The Bold\n";

  std::cout << "Enter Number: "; 
  std::cin >> answer1; 

  if (answer1 == 1) {
    hufflepuff += 10; 
  } 
  else if (answer1 == 2) {
    slytherin += 10; 
  } 
  else if (answer1 == 3) {
    ravenclaw += 10; 
  } 
  else if (answer1 == 4) {
    gryffindor += 10; 
  } 
  else {
    std::cout << "Invalid Input\n"; 
  }
  
  std::cout << "Q2) Dawn or Dusk? \n\n";
  std::cout << "   1) Dawn\n";
  std::cout << "   2) Dusk\n";
 
  std::cout << "Enter Number: "; 
  std::cin >> answer2;

  if (answer2 == 1) {
    gryffindor += 10;
    ravenclaw += 10;
  } 
  else if (answer2 == 2) {
    slytherin += 10;
    hufflepuff += 10; 
  } 
  else {
    std::cout << "Invalid Input\n"; 
  }

  std::cout << "Q3) Which kind of instrument most pleases your ear? \n\n";
  std::cout << "   1) The Violin\n";
  std::cout << "   2) The Trumpet\n";
  std::cout << "   3) The Piano\n";
  std::cout << "   4) The Drum\n";

  std::cout << "Enter Number: "; 
  std::cin >> answer3; 

  if (answer3 == 1) {
    slytherin += 10; 
  } 
  else if (answer3 == 2) {
    hufflepuff += 10; 
  } 
  else if (answer3 == 3) {
    ravenclaw += 10; 
  } 
  else if (answer3 == 4) {
    gryffindor += 10; 
  } 
  else {
    std::cout << "Invalid Input\n"; 
  }
  
  std::cout << "Q4) Which road tempts you the most? \n\n";
  std::cout << "   1) The wide, sunny grassy lane\n";
  std::cout << "   2) The narrow, dark, lantern-lit alley\n";
  std::cout << "   3) The twisting, leaf-strewn path through the woods\n";
  std::cout << "   4) The cobbled street path (ancient buildings)\n";

  std::cout << "Enter Number: "; 
  std::cin >> answer4; 

  if (answer4 == 1) {
    hufflepuff += 10; 
  } 
  else if (answer4 == 2) {
    slytherin += 10; 
  } 
  else if (answer4 == 3) {
    gryffindor += 10; 
  } 
  else if (answer4 == 4) {
    ravenclaw += 10; 
  } 
  else {
    std::cout << "Invalid Input\n"; 
  }

  if (gryffindor > max) {
    max = gryffindor;
    house = "Gryffindor";
  } 
  if (hufflepuff > max) {
    max = hufflepuff;
     house = "Hufflepuff";
  } 
  if (ravenclaw > max) {
    max = ravenclaw;
    house = "Ravenclaw";
} if (slytherin > max) {
    max = slytherin;
    house = "Slytherin";
  }

std::cout << house << "!\n"; 


  return 0; 
}











