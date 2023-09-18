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
    std::cout << "___________________________________________________________________________" << std::endl;
    std::cout << "\tExplain std::stack usage:" << std::endl;
    std::stack<int>            originalStack;
    //std::stack<int>::iterator  stackIter; -> ‘iterator’ is not a member of ‘std::stack’

    originalStack.push(10);
    originalStack.push(15);
    originalStack.push(3);
    originalStack.push(42);

    std::cout << "The top of the stack is the only element accessible for viewing or manipulation." << std::endl;
    std::cout << "Viewing or manipulating stack elements is always more complicated than it should be, for example:" << std::endl;
    std::cout << "\twhile (!originalStack.empty())" << std::endl;
    std::cout << "\t{" << std::endl;
    std::cout << "\t\tstd::cout << originalStack.top() << " ";" << std::endl;
    std::cout << "\t\toriginalStack.pop();" << std::endl;
    std::cout << "\t}" << std::endl;
    std::cout << "OUTPUT:" << std::endl;
    std::cout << "originalStack: \t";
    while (!originalStack.empty())
    {
        std::cout << originalStack.top() << " ";
        originalStack.pop();
    }
    std::cout << std::endl;
    std::cout << "It is necessary to delete every element from the stack (or do some engineering with recursive calls)" << std::endl;
    std::cout << "With an iterator, this would change." << std::endl;
}