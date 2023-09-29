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
		int		_unpairedNumberDeq;
		
		std::vector<int>	_input;
		std::vector<int>	_mainVector;
		std::vector<int>	_pendVector;
		std::vector<int>	_jacobSeqVector;
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
		void 	insertNumbersVector( void );
		void	positionsVector( void );
		
		void	sortDeque( void );
		void	mergeSort( std::deque<int>& S, int start, int end );
		void	insertNumbersDeque( void );
		void	positionsDeque( void );

	public:

		PmergeMe( void );
		PmergeMe( PmergeMe const& );
		~PmergeMe( void );

		PmergeMe& operator=( const PmergeMe &);

		void	merge( int, char ** );

		template<typename T>
		void	printSequence( const T& );

		template<typename T>
		void displaySortInfo(clock_t, const T& );

		template<typename T>
		void jacobsthalInsertSequence( T& );

		template<typename T>
		int binarySearch(T& deq, int nbr, int begin, int end);
};

#endif