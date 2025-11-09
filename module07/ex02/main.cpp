#include "Array.hpp"
#include <cstdlib>
#include <iostream>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }
//
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
// 		std::cout << "debug" <<std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

int main(void) {
  Array<int> a;
  Array<char> b(10);

  std::cout << "default constructor have null array and size: " << a.size()
            << std::endl;
  std::cout << "constructor with paramiter must allocate arr with nothing in "
               "side and size: "
            << a.size() << std::endl;
  std::cout << "print arr: " << std::endl;
  for (size_t i = 0; i < b.size(); i++)
    std::cout << "[" << b[i] << "]" << std::endl;

  std::cout << "assign value a - j and print check" << std::endl;

  char c = 'a';

  for (size_t i = 0; i < b.size(); i++)
    b[i] = c++;

  for (size_t i = 0; i < b.size(); i++)
    std::cout << "[" << b[i] << "]" << std::endl;

  std::cout << "try to access out of scope index:" << std::endl;
  try {
    b[10] = 10;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    b[-1] = 10;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
