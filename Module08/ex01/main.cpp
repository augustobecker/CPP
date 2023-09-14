#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <list>

void SubjectTests( void );
void SpanCopyOperationsTests( void );
void SpanShortestAndLongestTests( void );

int main( void )
{
    SubjectTests();
    SpanCopyOperationsTests();
    SpanShortestAndLongestTests();
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
    Span sp = Span(3);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);

    Span spCopyConstructor = Span(5);
    Span spCopyAssign = Span(8);

    spCopyAssign.addNumber(18);
    spCopyAssign.addNumber(9);
    spCopyAssign.addNumber(7);

    spCopyAssign = sp;

    std::cout << "| ";
    sp.displayElem();
    std::cout << "| ";
    spCopyConstructor.displayElem();
    std::cout << "| ";
    spCopyAssign.displayElem();
}

void SpanShortestAndLongestTests( void )
{
    std::cout << "_______________________________________" << std::endl;
    std::cout << "|________|| SPAN SPAN TESTS ||________| " << std::endl;
    Span sp = Span(3);
}