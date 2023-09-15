#include "Span.hpp"
#include <cstdlib>
#include <ctime>

void SubjectTests( void );
void SpanCopyOperationsTests( void );
void SpanShortestAndLongestTests( void );
void SpanAddNumberRangeTests( int size );

int main( void )
{
    srand(time(NULL));
    SubjectTests();
    SpanCopyOperationsTests();
    SpanShortestAndLongestTests();
    SpanAddNumberRangeTests( 10000 );
    SpanAddNumberRangeTests( 5 );
    return 0;
}

void SubjectTests( void )
{
    std::cout << "_______________________________________" << std::endl;
    std::cout << "|__________|| SUBJECT TESTS ||________| " << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "| shortest span: \t" << sp.shortestSpan() << std::endl;
    std::cout << "| longest span: \t" << sp.longestSpan() << std::endl;
    std::cout << "| ";
    sp.displayElem();
}

void SpanCopyOperationsTests( void )
{
    std::cout << "_______________________________________" << std::endl;
    std::cout << "|________|| SPAN COPY TESTS ||________| " << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(22);

    Span spCopyConstructor = Span(sp);
    Span spCopyAssign = Span(2);

    spCopyAssign.addNumber(18);
    spCopyAssign.addNumber(9);

    spCopyAssign = sp;

    Span spCopyAssignGreater = Span(8);

    spCopyAssignGreater.addNumber(8);
    spCopyAssignGreater.addNumber(7);
    spCopyAssignGreater.addNumber(1);
    spCopyAssignGreater.addNumber(66);
    spCopyAssignGreater.addNumber(4);
    spCopyAssignGreater.addNumber(91);
    spCopyAssignGreater.addNumber(88);
    spCopyAssignGreater.addNumber(100);

    spCopyAssignGreater = sp;

    Span spCopyAssignEmpty = Span(0);

    spCopyAssignEmpty = sp;

    std::cout << "| ";
    sp.displayElem();
    std::cout << "| ";
    spCopyConstructor.displayElem();
    std::cout << "| ";
    spCopyAssign.displayElem();
    std::cout << "| ";
    spCopyAssignGreater.displayElem();
    std::cout << "| ";
    spCopyAssignEmpty.displayElem();
}

void SpanShortestAndLongestTests( void )
{
    std::cout << "_______________________________________" << std::endl;
    std::cout << "|________|| SPAN SPAN TESTS ||________| " << std::endl;
    Span sp = Span(10);

    sp.addNumber(16);
    sp.addNumber(1);
    sp.addNumber(39);
    sp.addNumber(9);
    sp.addNumber(101);
    sp.addNumber(97);
    sp.addNumber(63);
    sp.addNumber(33);
    sp.addNumber(21);
    sp.addNumber(34);

    std::cout << "| ";
    sp.displayElem();

    try {
        std::cout << "| shortest span: \t" << sp.shortestSpan() << std::endl;
    } catch(std::exception &e){
 		std::cout << "| Exception: " << e.what() <<std::endl;
 	}
    try {
        std::cout << "| longest span: \t" << sp.longestSpan() << std::endl;
    } catch(std::exception &e){
 		std::cout << "| Exception: " << e.what() <<std::endl;
 	}
}

void SpanAddNumberRangeTests( int size )
{
    std::cout << "_______________________________________" << std::endl;
    std::cout << "|__|| SPAN ADD NUMBER RANGE TESTS ||__| " << std::endl;
    std::vector<int>	numbers;
    Span                sp(size);

    for (int i = 1; i <= size; ++i)
        numbers.push_back(i * (std::rand() % size));
    sp.addNumbersRange(numbers.begin(), numbers.end());
    std::cout << "| ";
    sp.displayElem();
    try {
        std::cout << "| shortest span: \t" << sp.shortestSpan() << std::endl;
    } catch(std::exception &e){
 		std::cout << "| Exception: " << e.what() <<std::endl;
 	}
    try {
        std::cout << "| longest span: \t" << sp.longestSpan() << std::endl;
    } catch(std::exception &e){
 		std::cout << "| Exception: " << e.what() <<std::endl;
 	}
}
