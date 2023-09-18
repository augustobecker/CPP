# include <iostream>
# include <stack>
# include "MutantStack.hpp"

void TestOriginalStack( void );
void TestMutantStackMemberFunctions( void );
void TestMutantStackIteratos( void );

int main(void)
{
    TestOriginalStack();
    TestMutantStackMemberFunctions();
    TestMutantStackIteratos();
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

void TestMutantStackMemberFunctions( void )
{
    std::cout << "___________________________________________________________________________" << std::endl;
    std::cout << " MUTANT STACK MEMBER FUNCTIONS" << std::endl;
    std::cout <<  "Create MutantStack<int>    mutant and numbers" << std::endl;
    MutantStack<int>    mutant;
    MutantStack<int>    numbers;

    std::cout <<  "1. PUSH METHOD: " << std::endl;
    std::cout <<  "\tmutant.push(3);" << std::endl;
	mutant.push(3);
	std::cout <<  "\tmutant.push(9);" << std::endl;
	mutant.push(9);
    std::cout <<  "\tmutant.push(2001);" << std::endl;
	mutant.push(2001);

    std::cout << "2. SIZE METHOD: " << std::endl;
    std::cout <<  "\tmutant.size();  \t-> size: " << mutant.size() << std::endl;
    std::cout <<  "\tnumbers.size(); \t-> size: " << numbers.size() << std::endl;
	
    std::cout << "3. EMPTY METHOD: " << std::endl;
	std::cout << "\tmutant.empty(); \t->: " << std::boolalpha << mutant.empty() << std::endl;
    std::cout << "\tnumbers.empty(); \t->: " << std::boolalpha << numbers.empty() << std::endl;

    std::cout << "4. TOP METHOD: " << std::endl;
    if (!mutant.empty())
        std::cout <<  "\tmutant.top();    \t-> top: " << mutant.top() << std::endl;
    if (!numbers.empty())
        std::cout <<  "\tnumbers.top(); \t-> top: " << numbers.top() << std::endl;

}

void TestMutantStackIteratos( void )
{
    std::cout << "___________________________________________________________________________" << std::endl;
    std::cout << " MUTANT ITERATORS" << std::endl;
	
    std::cout <<  "Create MutantStack<int>    mutant and numbers" << std::endl;
    MutantStack<int>    mutant;
    MutantStack<int>    numbers;

	mutant.push(3);
	mutant.push(9);
	mutant.push(2001);
    mutant.push(4);
    mutant.push(3);
    mutant.push(22);
    mutant.push(0);

    std::cout <<  "\tmutant.size();  \t-> size: " << mutant.size() << std::endl;
    std::cout <<  "\tnumbers.size(); \t-> size: " << numbers.size() << std::endl;

    std::cout <<  "Create MutantStack<int>::iterator    for mutant" << std::endl;
	MutantStack<int>::iterator iterBegin = mutant.begin();
	MutantStack<int>::iterator iterEnd = mutant.end();
	
	std::cout << "5. DISPLAY STACK USING ITERATORS:" << std::endl;
    std::cout <<  " MutantStack<int>    mutant: ";
	while (iterBegin != iterEnd)
	{
		std::cout << *iterBegin << " | ";
		++iterBegin;
	}
    std::cout << std::endl;

    iterBegin = numbers.begin();
	iterEnd = numbers.end();
    
    while (iterBegin != iterEnd)
	{
		std::cout << *iterBegin << " | ";
		++iterBegin;
	}
    std::cout << std::endl;

    std::cout <<  "Create MutantStack<int>::reverse_iterator    for mutant" << std::endl;
	MutantStack<int>::reverse_iterator reverseIterBegin = mutant.rbegin();
	MutantStack<int>::reverse_iterator reverseIterEnd = mutant.rend();
	
	std::cout << "6. DISPLAY STACK USING REVERSE ITERATORS:" << std::endl;
    std::cout <<  " MutantStack<int>    mutant: ";
	while (reverseIterBegin != reverseIterEnd)
	{
		std::cout << *reverseIterBegin << " | ";
		++reverseIterBegin++;
	}
    std::cout << std::endl;

    reverseIterBegin = numbers.rbegin();
	reverseIterEnd = numbers.rend();

    while (reverseIterBegin != reverseIterEnd)
	{
		std::cout << *reverseIterBegin << " | ";
		++reverseIterBegin++;
	}
    std::cout << std::endl;
}