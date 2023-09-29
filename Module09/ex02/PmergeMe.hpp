#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstring>
# include <algorithm>
# include <set>
# include <typeinfo>

class PmergeMe
{

	private:
		float	_time;
		int		_unpairedNumberVec;
		int		_straggler;
		
		std::vector<int>	_input;
		std::vector<int>	_mainVec;
		std::vector<int>	_pendVec;
		std::vector<int>	_jacobSeqVec;
		std::vector<int>	_posVec;

		std::vector<std::pair<int, int> >	_pairVec;
		
		std::deque<int>		_inputDeq;
		std::deque<int>		_mainDeque;
		std::deque<int>		_pendDeque;
		std::deque<int>		_jacobSeqDeq;
		std::deque<int>		_posDeq;

		std::deque<std::pair<int, int> >	_pairDeq;
		
		void	populateContainers( int, char ** );

		void	printUnsortedSequence( int );
		int		jacobsthal(int n);

		void	sortVector( void );
		void	mergeSort( std::vector<int>& S, int start, int end );
		int 	binarySearch( std::vector<int> vec, int n, int begin, int end );
		void 	insertNumbersVec( void );
		void	positionsVec( void );
		void	jacobInsertSeqVec( void );
		
		void	sortDeque( void );
		void	mergeSort( std::deque<int>& S, int start, int end );
		int		binarySearch( std::deque<int> deq, int n, int begin, int end );
		void	insertNumbersDeque( void );
		void	positionsDeque( void );
		void	jacobInsertSeqDeq( void );

	public:

		PmergeMe( void );
		PmergeMe( PmergeMe const& );
		~PmergeMe( void );

		PmergeMe& operator=( const PmergeMe &);

		void	merge( int, char ** );

		template<typename T>
		void	printSequence( const T& );

		template<typename T>
		void displaySortInfo(clock_t start, const T& mainSequence);

};

#endif