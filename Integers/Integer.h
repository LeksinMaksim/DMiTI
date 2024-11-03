#include <iostream>
#include <vector>

class Integer{
  public:
    int sign; // 0 - plus, 1 - minus
    int size;
    std::vector<int> digits;
    Integer();
    Integer(int sign, int size, std::vector<int> digits);
    Integer(const Integer& another_number);
    Integer(int number);
    Integer operator=(Integer& another_number);
};