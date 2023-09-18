#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

void testsSubjectMain( void );
void testArrayLimits( void );
void testArrayCopy( void );
void testArraySizeMethod( void );

void displayArray( Array<int> numbers, unsigned int size );

int main( void )
{
    std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "1. Tests from Subject: " << std::endl;
    testsSubjectMain();
    std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "2. Test Array Limits: " << std::endl;
    testArrayLimits();
    std::cout << "__________________________________________________________________" << std::endl;
    std::cout << "3. Test Array Copy: " << std::endl;
    testArrayCopy();
    std::cout << "__________________________________________________________________" << std::endl;
    std::cout << "4. Test Array Size Method: " << std::endl;
    testArraySizeMethod();
    std::cout << "__________________________________________________________________" << std::endl;
    return (0);
}

void testsSubjectMain( void )
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
}

void testArrayLimits( void )
{
    std::cout << "2. 1. create Array<int> numbers(100)" << std::endl;
    std::cout << "\t(it should work)" << std::endl;
    Array<int> numbers(100);

    for (int i = 0; i < 100; i++)
    {
        numbers[i] = i + 39;
    }
    
    std::cout << "\n2. 2. trying to access numbers[99]" << std::endl;
    std::cout << "\t(it should work)" << std::endl;
    try
    {
        std::cout << "numbers[99] : " << numbers[99]  << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n2. 3. trying to access numbers[100]" << std::endl;
    std::cout << "\t(it should throw an exception)" << std::endl;
    try
    {
        std::cout << "numbers[100] : " << numbers[100]  << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n2. 4. trying to access numbers[0]" << std::endl;
    std::cout << "\t(it should work)" << std::endl;
    try
    {
        std::cout << "numbers[0] : " << numbers[0]  << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n2. 5. trying to access numbers[-1]" << std::endl;
    std::cout << "\t(it should work - in python) (in cpp it should throw an exception)" << std::endl;
    try
    {
        std::cout << "numbers[-1] : " << numbers[-1]  << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::cout << std::endl;

}

void testArrayCopy( void )
{
    std::cout << "3. 1. create Array<int> numbers(10), copyGreater(15), copySmaller(5) and copySame(10)" << std::endl;
    Array<int> numbers(10);
    Array<int> copyGreater(15);
    Array<int> copySmaller(5);
    Array<int> copySame(10);

    for (int i = 0; i < 10; i++)
    {
        numbers[i] = i + 39;
    }

    for (int i = 0; i < 15; i++)
    {
        copyGreater[i] = i + 13;
    }

    for (int i = 0; i < 5; i++)
    {
        copySmaller[i] = i + 102;
    }

    for (int i = 0; i < 10; i++)
    {
        copySame[i] = i + 1;
    }

    std::cout << "numbers: \t";
    displayArray(numbers, 10);
    std::cout << "copyGreater: \t";
    displayArray(copyGreater, 15);
    std::cout << "copySmaller: \t";
    displayArray(copySmaller, 5);
    std::cout << "copySame: \t";
    displayArray(copySame, 10);
    
    std::cout << "\n3. 2. copy copyGreater = numbers" << std::endl;

    copyGreater = numbers;
    std::cout << "numbers: \t";
    displayArray(numbers, 10);
    std::cout << "copyGreater: \t";
    displayArray(copyGreater, 15);

    std::cout << "\n3. 2. copy copySmaller = numbers" << std::endl;

    copySmaller = numbers;
    std::cout << "numbers: \t";
    displayArray(numbers, 10);
    std::cout << "copySmaller: \t";
    displayArray(copySmaller, 5);

    std::cout << "\n3. 3. copy copySame = numbers" << std::endl;

    copySame = numbers;
    std::cout << "numbers: \t";
    displayArray(numbers, 10);
    std::cout << "copySame: \t";
    displayArray(copySame, 10);

    std::cout << std::endl;
}

void testArraySizeMethod( void )
{
    std::cout << "4. 1. create Array<int> numbers(10), nbrs(15), arr(5) and test(10)" << std::endl;
    Array<int> numbers(10);
    Array<int> nbrs(15);
    Array<int> arr(5);
    Array<int> test(10);

    
    std::cout << "\n4. 2. size method" << std::endl;

    std::cout << "numbers size: \t" << numbers.size() << std::endl;
    std::cout << "nbrs size: \t" << nbrs.size() << std::endl;
    std::cout << "arr size: \t" << arr.size() << std::endl;
    std::cout << "test size: \t" << test.size() << std::endl;

    std::cout << std::endl;
}

void displayArray( Array<int> numbers, unsigned int size )
{
    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}