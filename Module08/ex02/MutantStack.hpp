#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:

	MutantStack( void ) {};
	MutantStack(const MutantStack& obj) { *this = obj; };
	~MutantStack( void ) {};

	MutantStack& operator=(const MutantStack& toCopyFrom) 
	{
		if (this != &toCopyFrom)
			std::stack<T>::operator=(toCopyFrom);
		return (*this);
	};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator	            begin(void)	{ return (std::stack<T>::c.begin()); }
	iterator	            end(void) { return (std::stack<T>::c.end()); }
	
	reverse_iterator	    rbegin(void)	{ return (std::stack<T>::c.rbegin()); }
	reverse_iterator	    rend(void)	{ return (std::stack<T>::c.rend()); }

	
	const_iterator	        cbegin(void)	{ return (std::stack<T>::c.cbegin()); }
	const_iterator	        cend(void) { return (std::stack<T>::c.cend()); }

	const_reverse_iterator	crbegin(void)	{ return (std::stack<T>::c.crbegin()); }
	const_reverse_iterator	crend(void) { return (std::stack<T>::c.crend()); }
};

#endif