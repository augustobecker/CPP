# include <iostream>
# include <stack>
//# include "MutantStack.hpp"

void TestOriginalStack( void );

int main(void)
{
    TestOriginalStack();
    return (0);
}

void TestOriginalStack( void )
{
    std::cout << "________________________________________" << std::endl;
    std::stack<int>            originalStack;
    //std::stack<int>::iterator  stackIter; -> ‘iterator’ is not a member of ‘std::stack’

    originalStack.push(10);
    originalStack.push(15);
    originalStack.push(3);
    originalStack.push(42);

    std::cout << "originalStack: \t";
    while (!originalStack.empty())
    {
        std::cout << originalStack.top() << " ";
        originalStack.pop();
    }
    std::cout << std::endl;

    try
    {
        std::stack<int>::iterator  stackIter;
    } catch(std::exception& e){
        std::cout << "| " << e.what() << " to C\t\t      |" << std::endl;
    }
     
}