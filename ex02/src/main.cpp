#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << "--- 1. Mandatory 42 Intra Test ---" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(std::time(NULL));
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }

	{
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    bool isSame = true;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "Error: didn't save the same value!!" << std::endl;
            isSame = false;
            break;
        }
    }
    if (isSame)
        std::cout << "Deep copy and memory management test passed!" << std::endl;

    std::cout << "\n--- 2. Out of Bounds Exception Tests ---" << std::endl;
    try
    {
        std::cout << "Trying to access index -2... ";
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    
    try
    {
        std::cout << "Trying to access index MAX_VAL... ";
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();
    }
    delete [] mirror;

    std::cout << "\n--- 3. Additional Custom Tests ---" << std::endl;
    
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    try 
    {
        std::cout << "Trying to access index 0 of empty array... ";
        empty[0] = 1; 
    } 
    catch(const std::exception& e) 
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    const Array<int> constArr(5);
    std::cout << "Const array size: " << constArr.size() << std::endl;
    std::cout << "Const array element 0 (default initialized): " << constArr[0] << std::endl;
    // constArr[0] = 42; // Compile-time error: cannot assign to const object
    return 0;
}