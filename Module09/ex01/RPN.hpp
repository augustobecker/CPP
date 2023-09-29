#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <stack>

class RPN
{
	private:

		RPN( void );
		RPN( const RPN & );

		static void calculateOperatorExpression( std::stack<int> &, char const );

	public:

		~RPN(void);

		RPN &operator=( const RPN & );

		static void	calculate( std::string );

		class	BadInputException : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class	InvalidArgumentException : public std::exception
		{
			public:
			const char* what() const throw();
		};

};

#endif