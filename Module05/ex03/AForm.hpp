#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include <stdlib.h> 

class Bureaucrat;

class AForm
{

private:

	const std::string	_name;
	bool                _isSigned;
	const int			_requiredGradeToSign;
	const int	        _requiredGradeToExecute;

public:

	static const int	higestGrade = 1;
	static const int	lowestGrade = 150;

	AForm( std::string, int, int );
	virtual ~AForm( void );

	AForm( const AForm& );
	AForm& operator=( const AForm& );

	std::string 		getName( void ) const;
	bool				getIsSigned( void ) const;
	int					getRequiredGradeToSign( void ) const;
	int					getRequiredGradeToExecute( void ) const;

	virtual std::string getTarget( void ) const = 0;

    void				setIsSigned( bool ) ;

	void				beSigned( Bureaucrat const& );
	virtual void		execute( Bureaucrat const& ) const;

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

	class NotSignedException : public std::exception
	{

	public:
        const char* what() const throw ();
	};

};

#endif
