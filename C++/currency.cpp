#include <iostream>

int main() 
{
  double pesos, reais, soles, dollars; 

  std::cout << "Enter number of Colombian Pesos: "; // 0.045
  std::cin >> pesos; 
  std::cout << "Enter number of Brazilian Reais: "; // 0.18
  std::cin >> reais; 
  std::cout << "Enter number of Peruvian Soles: "; // 0.28 
  std::cin >> soles; 
  
  dollars = (.045 * pesos) + (.18 * reais) + (.28 * soles); 

  std::cout << "US Dollars = $" << dollars << "\n"; 
}