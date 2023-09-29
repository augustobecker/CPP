#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{
	this->_unpairedNumberDeq = -1;
	this->_unpairedNumberVec = -1;
}

PmergeMe::~PmergeMe( void )
{

}

PmergeMe::PmergeMe( const PmergeMe &obj )
{
	*this = obj;
}

PmergeMe &PmergeMe::operator=( const PmergeMe &toCopyFrom )
{
	if (this != &toCopyFrom)
		return (*this);
	return (*this);
}

void	PmergeMe::merge( int argc, char **argv )
{
	PmergeMe::populateContainers(argc, argv);
	PmergeMe::printUnsortedSequence(argc);
	PmergeMe::sortVector();
	PmergeMe::sortDeque();
}

void PmergeMe::populateContainers( int argc, char **argv )
{
	std::set<int>	numbers;

	for (int i = 1; i < argc; i++)
	{
		int length = std::strlen(argv[i]);
		for (int j = 0; j < length; j++ )
		{
			if (!isdigit(argv[i][j]) && argv[i][j] != '+')
				throw std::invalid_argument("Error: Invalid argument.");
		}
		
		int	num = atoi(argv[i]);
		if (num < 0)
			throw std::runtime_error("Error: Negative Numbers are invalid");
        if (!numbers.insert(num).second)
            throw std::runtime_error("Error: Duplicate number detected.");
		_input.push_back(num);
		_inputDeq.push_back(num);
	}
}

template<typename T>
void	PmergeMe::printSequence(const T& sequence)
{
    typename T::const_iterator it;
	int	i =  0;
	for (it = sequence.begin(); it != sequence.end(); ++it) {
        std::cout << *it << " ";
		if (i == 15){
			std::cout << "[...]";
			break;
		}
		i++;
    }
    std::cout << std::endl;
}

void	PmergeMe::printUnsortedSequence( int argc )
{
	std::cout << "Before: ";
	for(int i = 0; i < (argc - 1) ; i++)
	{
		std::cout << _input[i] << " ";
		if (i == 15)
		{
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
}

int PmergeMe::jacobsthal( int nbr )
{
    if (nbr == 0)
		return (0);
    if (nbr == 1)
		return (1);

    int prev1 = 0;
    int prev2 = 1;
    int current = 0;

    for (int i = 2; i <= nbr; ++i)
	{
        current = prev1 + 2 * prev2;
        prev1 = prev2;
        prev2 = current;
    }
    return current;
}

template<typename T>
void PmergeMe::jacobsthalInsertSequence( T& sequence, size_t maxSize )
{
	size_t	jacobIndex;
	int		index;

	index = 3;
	while ((jacobIndex = PmergeMe::jacobsthal(index)) < maxSize - 1)
	{
		sequence.push_back(jacobIndex);
		index++;
	}
}

void PmergeMe::positionsVector( void )
{
    if (this->_pendVector.empty())
        return;
    PmergeMe::jacobsthalInsertSequence(_jacobSeqVector, _pendVector.size());
    size_t lastPos = 1;
    size_t val = 1;
    for (size_t i = 0; i < _jacobSeqVector.size(); i++)
    {
        val = _jacobSeqVector.at(i);
        _posVec.push_back(val);

        size_t pos = val - 1;
        while (pos > lastPos)
        {
            _posVec.push_back(pos);
            pos--;
        }
        lastPos = val;
    }

    while (val++ < _pendVector.size())
        _posVec.push_back(val);
}

void PmergeMe::insertNumbersVector( void )
{
	std::vector<int>::iterator	it;
    size_t	addCount = 0;

    PmergeMe::positionsVector();
	for (it = _posVec.begin(); it < _posVec.end(); it++)
    {
        int nbr = _pendVector.at(*it - 1);
        size_t endPos = *it + addCount;
        size_t pos = PmergeMe::binarySearch(_mainVector, nbr, 0, endPos);
        _mainVector.insert(_mainVector.begin() + pos, nbr);
		addCount++;
    }
    if (_unpairedNumberVec != -1)
    {
        size_t nbr = _unpairedNumberVec;
        size_t pos = PmergeMe::binarySearch(_mainVector, nbr, 0, _mainVector.size() - 1);
        _mainVector.insert(_mainVector.begin() + pos, nbr);
    }
}

void PmergeMe::mergeSort( std::vector<int>& vector, int start, int end )
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    PmergeMe::mergeSort(vector, start, mid);
    PmergeMe::mergeSort(vector, mid + 1, end);

    std::vector<int> sorted;

    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end)
	{
        if (vector[left] <= vector[right]) {
            sorted.push_back(vector[left]);
            left++;
        } else {
            sorted.push_back(vector[right]);
            right++;
        }
    }
    while (left <= mid)
	{
        sorted.push_back(vector[left]);
        left++;
    }
    while (right <= end)
	{
        sorted.push_back(vector[right]);
        right++;
    }
    for (int i = start; i <= end; i++)
        vector[i] = sorted[i - start];
}

void	PmergeMe::sortVector( void )
{
	clock_t start = clock();
	size_t	size = _input.size();
	
	if (size % 2 == 1)
	{
		_unpairedNumberVec = _input.back();
		_input.pop_back();
	}

	for (size_t i = 0; i < size - 1; i += 2)
		_pairVec.push_back(std::make_pair(_input[i], _input[i + 1]));

	for (size_t i = 0; i < _pairVec.size(); i++)
	{
		if (_pairVec[i].first < _pairVec[i].second){
			std::swap(_pairVec[i].first, _pairVec[i].second);
		}
		_mainVector.push_back(_pairVec[i].first);
		_pendVector.push_back(_pairVec[i].second);
	}
	PmergeMe::mergeSort(_mainVector, 0, _mainVector.size() - 1);
	_mainVector.insert(_mainVector.begin(), _pendVector[0]);
	PmergeMe::insertNumbersVector();
	PmergeMe::displaySortInfo(start, _mainVector);
}

void PmergeMe::positionsDeque( void )
{
	if (_pendDeque.empty())
		return;

	PmergeMe::jacobsthalInsertSequence(_jacobSeqDeq, _pendDeque.size());
	size_t lastPos = 1;
	size_t val = 1;
	while (!_jacobSeqDeq.empty())
	{
		val = _jacobSeqDeq.front();

		_jacobSeqDeq.pop_front();
		_posDeq.push_back(val);

		size_t pos = val - 1;
		while (pos > lastPos)
		{
			_posDeq.push_back(pos);
			pos--;
		}
		lastPos = val;
	}
	while (val++ < _pendDeque.size())
		_posDeq.push_back(val);
}

void PmergeMe::insertNumbersDeque( void )
{
	std::deque<int>::iterator it;
	size_t addCount = 0;

	PmergeMe::positionsDeque();
	for (it = _posDeq.begin(); it < _posDeq.end(); it++)
	{
		int n = _pendDeque.at(*it - 1);

		size_t endPos = *it + addCount;
		size_t pos = PmergeMe::binarySearch(_mainDeque, n, 0, endPos);
		_mainDeque.insert(_mainDeque.begin() + pos, n);
		addCount++;
	}
	if (_unpairedNumberDeq != -1)
	{
		size_t nbr = _unpairedNumberDeq;
		size_t pos = PmergeMe::binarySearch(_mainDeque, nbr, 0, _mainDeque.size() - 1);
		_mainDeque.insert(_mainDeque.begin() + pos, nbr);
	}
}

void PmergeMe::mergeSort( std::deque<int>& deq, int start, int end )
{
    if (start >= end)
        return ;

    int mid = (start + end) / 2;

    mergeSort(deq, start, mid);
    mergeSort(deq, mid + 1, end);

    std::vector<int> sorted;

    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end)
	{
        if (deq[left] <= deq[right]) {
            sorted.push_back(deq[left]);
            left++;
        } else {
            sorted.push_back(deq[right]);
            right++;
        }
    }
    while (left <= mid)
	{
        sorted.push_back(deq[left]);
        left++;
    }
    while (right <= end)
	{
        sorted.push_back(deq[right]);
        right++;
    }
    for (int i = start; i <= end; i++)
	{
        deq[i] = sorted[i - start];
    }
}

void	PmergeMe::sortDeque( void )
{
	clock_t start = clock();
	size_t	size = _inputDeq.size();
	
	if (size % 2 == 1)
	{
		_unpairedNumberDeq = _inputDeq.back();
		_inputDeq.pop_back();
	}
	for (size_t i = 0; i < size - 1; i += 2){
		_pairDeq.push_back(std::make_pair(_inputDeq[i], _inputDeq[i + 1]));
	}
	for (size_t i = 0; i < _pairDeq.size(); i++){
		if (_pairDeq[i].first < _pairDeq[i].second)
			std::swap(_pairDeq[i].first, _pairDeq[i].second);
		_mainDeque.push_back(_pairDeq[i].first);
		_pendDeque.push_back(_pairDeq[i].second);
	}
	
	mergeSort(_mainDeque, 0, _mainDeque.size() - 1);
	_mainDeque.push_front(_pendDeque[0]);

	insertNumbersDeque();

	displaySortInfo(start, _mainDeque);
}

template<typename T>
void PmergeMe::displaySortInfo(clock_t start, const T& mainSequence)
{
    clock_t end = clock();
    double timePassedMs = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    std::cout << "After:  ";
    printSequence(mainSequence);
    std::cout << "Time to process a range of " << mainSequence.size();
    std::cout << " elements with " << (typeid(mainSequence) == typeid(std::vector<int>) ? "std::vector" : "std::deque");
    std::cout << " : " << timePassedMs << " ms" << std::endl;
}

template<typename T>
int PmergeMe::binarySearch(T& container, int nbr, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (nbr == container.at(mid))
			return (mid);

		if (nbr > container.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (nbr > container.at(mid))
		return (mid + 1);
	else
		return (mid);
}
