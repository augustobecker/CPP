#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

private:

	const std::string	_name;
	bool                _isSigned;
	const int			_requiredGradeToSign;
	const int	        _requiredGradeToExecute;

public:

	static const int	higestGrade = 1;
	static const int	lowestGrade = 150;

	Form( std::string, int, int );
	virtual ~Form( void );

	Form( const Form& );
	Form& operator=( const Form& );

	std::string getName( void ) const;
	bool		getIsSigned( void ) const;
	int			getRequiredGradeToSign( void ) const;
	int			getRequiredGradeToExecute( void ) const;

    void        setIsSigned( bool ) ;

	void beSigned( const Bureaucrat& );

	virtual std::string getTarget( void ) const = 0;

	class GradeTooHighException : public std::exception
	{

	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{

	public:
        const char* what() const throw ();
	};

};

#endif
