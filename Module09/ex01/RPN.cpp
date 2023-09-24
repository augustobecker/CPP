#include "RPN.hpp"

RPN::RPN( void )
{

}

RPN::~RPN( void )
{

}

RPN::RPN( const RPN &obj )
{
	*this = obj;
}

RPN &RPN::operator=( const RPN &toCopyFrom )
{
	if (this != &toCopyFrom)
		return (*this);
	return (*this);
}

void RPN::calculateOperatorExpression( std::stack<int> &stack, char const op )
{
	int operand[2];

	operand[0] = stack.top();
	stack.pop();
	operand[1] = stack.top();
	stack.pop();
	switch (op)
	{
		case '+':
			stack.push(operand[1] + operand[0]);
			break;
		case '-':
			stack.push(operand[1] - operand[0]);
			break;
		case '/':
			if (operand[0] == 0)
                throw std::invalid_argument("Division by zero");
			stack.push(operand[1] / operand[0]);
			break;
		case '*':
			stack.push(operand[1] * operand[0]);
			break;
		default:
			throw std::invalid_argument("Invalid argument: " + op);
    }
}

void RPN::calculate( std::string input )
{
	std::stack<int>	stack;
	std::string						validInput = "0123456789 +-/*";
	std::string::iterator 			currentChar;

	for (currentChar = input.begin(); currentChar != input.end(); currentChar++)
	{
		if (validInput.find(*currentChar) == std::string::npos)
			throw InvalidArgumentException();
		if (std::isdigit(*currentChar))
			stack.push(*currentChar - '0');
		if (*currentChar != ' ' && !std::isdigit(*currentChar))
		{
			if (stack.size() < 2)
				throw RPN::BadInputException();
			else
				calculateOperatorExpression(stack, *currentChar);
		}
	}
	if (stack.size() != 1)
		throw(RPN::BadInputException());
	std::cout << stack.top() << std::endl;
}

const char* RPN::BadInputException::what() const throw()
{
	return "Error: bad input";
}

const char* RPN::InvalidArgumentException::what() const throw()
{
	return "Error: invalid argument, valid arguments are \"0123456789 +-/*\" only";
}