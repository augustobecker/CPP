#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{
	this->_straggler = -1;
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
	populateContainers(argc, argv);
	printUnsortedSequence(argc);
	sortVector();
	sortDeque();
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
void	PmergeMe::printSequence(const T& sequence) {
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

int PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void PmergeMe::jacobInsertSeqVec()
{
    size_t size;
    size_t jacobIndex;
    int index;

    size = _pendVec.size();
    index = 3;

    while ((jacobIndex = this->jacobsthal(index)) < size - 1)
    {
        this->_jacobSeqVec.push_back(jacobIndex);
        index++;
    }
}

void PmergeMe::positionsVec()
{
    if (this->_pendVec.empty())
        return;

    this->jacobInsertSeqVec();
    size_t lastPos = 1;
    size_t val = 1;
    for (size_t i = 0; i < this->_jacobSeqVec.size(); i++)
    {
        val = this->_jacobSeqVec.at(i);
        this->_posVec.push_back(val);

        size_t pos = val - 1;
        while (pos > lastPos)
        {
            this->_posVec.push_back(pos);
            pos--;
        }
        lastPos = val;
    }

    while (val++ < this->_pendVec.size())
        this->_posVec.push_back(val);
}

int PmergeMe::binarySearch(std::vector<int> vec, int n, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (n == vec.at(mid))
			return (mid);

		if (n > vec.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (n > vec.at(mid))
		return (mid + 1);
	else
		return (mid);
}

void PmergeMe::insertNumbersVec()
{
	std::vector<int>::iterator	it;
    size_t addCount = 0;

    this->positionsVec();
	for (it = this->_posVec.begin(); it < this->_posVec.end(); it++)
    {
        int n = this->_pendVec.at(*it - 1);
        size_t endPos = *it + addCount;
        size_t pos = binarySearch(this->_mainVec, n, 0, endPos);
        this->_mainVec.insert(this->_mainVec.begin() + pos, n);
		addCount++;
    }
    if (_unpairedNumberVec != -1)
    {
        size_t n = _unpairedNumberVec;
        size_t pos = binarySearch(this->_mainVec, n, 0, this->_mainVec.size() - 1);
        this->_mainVec.insert(this->_mainVec.begin() + pos, n);
    }
}

void PmergeMe::mergeSort(std::vector<int>& S, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;

    mergeSort(S, start, mid);
    mergeSort(S, mid + 1, end);

    std::vector<int> sorted;

    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end) {
        if (S[left] <= S[right]) {
            sorted.push_back(S[left]);
            left++;
        } else {
            sorted.push_back(S[right]);
            right++;
        }
    }

    while (left <= mid) {
        sorted.push_back(S[left]);
        left++;
    }

    while (right <= end) {
        sorted.push_back(S[right]);
        right++;
    }

    for (int i = start; i <= end; i++) {
        S[i] = sorted[i - start];
    }
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
		_mainVec.push_back(_pairVec[i].first);
		_pendVec.push_back(_pairVec[i].second);
	}
	mergeSort(_mainVec, 0, _mainVec.size() - 1);
	_mainVec.insert(_mainVec.begin(), _pendVec[0]);
	insertNumbersVec();

	displaySortInfo(start, _mainVec);
}

int PmergeMe::binarySearch(std::deque<int> deq, int n, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (n == deq.at(mid))
			return (mid);

		if (n > deq.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (n > deq.at(mid))
		return (mid + 1);
	else
		return (mid);
}

void PmergeMe::jacobInsertSeqDeq()
{
	size_t size;
	size_t jacobIndex;
	int index;

	size = this->_pendDeque.size();
	index = 3;

	while ((jacobIndex = this->jacobsthal(index)) < size - 1)
	{
		this->_jacobSeqDeq.push_back(jacobIndex);
		index++;
	}
}

void PmergeMe::positionsDeque()
{
	if (this->_pendDeque.empty())
		return;

	this->jacobInsertSeqDeq();
	size_t lastPos = 1;
	size_t val = 1;
	while (!this->_jacobSeqDeq.empty())
	{
		val = this->_jacobSeqDeq.front();

		this->_jacobSeqDeq.pop_front();
		this->_posDeq.push_back(val);

		size_t pos = val - 1;
		while (pos > lastPos)
		{
			this->_posDeq.push_back(pos);
			pos--;
		}
		lastPos = val;
	}
	while (val++ < this->_pendDeque.size())
		this->_posDeq.push_back(val);
}

void PmergeMe::insertNumbersDeque()
{
	std::deque<int>::iterator it;
	size_t addCount = 0;

	this->positionsDeque();
	for (it = this->_posDeq.begin(); it < this->_posDeq.end(); it++)
	{
		int n = this->_pendDeque.at(*it - 1);

		size_t endPos = *it + addCount;
		size_t pos = this->binarySearch(this->_mainDeque, n, 0, endPos);
		this->_mainDeque.insert(this->_mainDeque.begin() + pos, n);
		addCount++;
	}
	if (_straggler != -1)
	{
		size_t n = _straggler;
		size_t pos = this->binarySearch(this->_mainDeque, n, 0, this->_mainDeque.size() - 1);
		this->_mainDeque.insert(this->_mainDeque.begin() + pos, n);
	}
}

void PmergeMe::mergeSort(std::deque<int>& S, int start, int end)
{
    if (start >= end)
        return ;

    int mid = (start + end) / 2;

    mergeSort(S, start, mid);
    mergeSort(S, mid + 1, end);

    std::vector<int> sorted;

    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end) {
        if (S[left] <= S[right]) {
            sorted.push_back(S[left]);
            left++;
        } else {
            sorted.push_back(S[right]);
            right++;
        }
    }

    while (left <= mid) {
        sorted.push_back(S[left]);
        left++;
    }

    while (right <= end) {
        sorted.push_back(S[right]);
        right++;
    }

    for (int i = start; i <= end; i++) {
        S[i] = sorted[i - start];
    }
}

void	PmergeMe::sortDeque( void )
{
	clock_t start = clock();
	size_t	size = _inputDeq.size();
	
	if (size % 2 == 1){
		_straggler = _inputDeq.back();
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
