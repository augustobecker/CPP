#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base* generate( void )
{
    int random;

    std::srand(time(NULL));
    random = std::rand() % 3;
    switch (random)
    {
        case 0:
            return new A;
            break;
        case 1:
            return new B;
            break;
        case 2:
            return new C;
            break;
    }
    return (NULL);
}

void identify(Base* ptr) {
    if (dynamic_cast<A*>(ptr))
        std::cout << "Pointer to A" << std::endl;
    else if (dynamic_cast<B*>(ptr))
        std::cout << "Pointer to B" << std::endl;
    else if (dynamic_cast<C*>(ptr))
        std::cout << "Pointer to C" << std::endl;
    else
        std::cout << "Unknown Instance Class" << std::endl;
}

void identify(Base& ref) {
    try {
        A& a = dynamic_cast<A& >(ref);
        if (&a == &ref)
            std::cout << "Reference to A" << std::endl;
    }
    catch(std::exception& e){
        std::cout << e.what() << " to A" << std::endl;
    }

    try {
        B& b = dynamic_cast<B& >(ref);
        if (&b == &ref)
            std::cout << "Reference to B" << std::endl;
    }
    catch(std::exception& e){
        std::cout << e.what() << " to B" << std::endl;
    }

    try {
        C& c = dynamic_cast<C& >(ref);
        if (&c == &ref)
            std::cout << "Reference to C" << std::endl;
    }
    catch(std::exception& e){
        std::cout << e.what() << " to C" << std::endl;
    }
}


int main (void)
{
	A       *a = new A();
	B       *b = new B();
	C       *c = new C();
	Base    *random = generate();

    std::cout << "_______________________________________" << std::endl;
    std::cout << "|__________|| CLASS A TESTS ||________| " << std::endl;
	identify(a);
	identify(*a);
    std::cout << std::endl;

	std::cout << "_______________________________________" << std::endl;
    std::cout << "|__________|| CLASS B TESTS ||________| " << std::endl;
	identify(b);
	identify(*b);
    std::cout << std::endl;

	std::cout << "_______________________________________" << std::endl;
    std::cout << "|__________|| CLASS C TESTS ||________| " << std::endl;
	identify(c);
	identify(*c);
    std::cout << std::endl;

	std::cout << "_______________________________________" << std::endl;
    std::cout << "|________|| RANDOM CLASS TESTS ||_____| " << std::endl;
	identify(random);
	identify(*random);
    std::cout << std::endl;

	delete (a);
	delete (b);
	delete (c);
	delete (random);

  	return (0);
}
