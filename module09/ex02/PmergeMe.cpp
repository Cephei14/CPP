#include "PmergeMe.hpp"

#ifdef EVAL_MODE
int Number::cnt = 0;
#endif

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if(this != &other) {
        this->_vector = other._vector;
        this->_deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::Start(int ac, char **av)
{
    for(int i = 1; i < ac; i++)
    {
        std::string str = av[i];
        for(size_t j = 0; j < str.length(); j++) {
            if(!isdigit(str[j])) {
                std::cerr << "Error : please enter a positive number." << std::endl;
                return;
            }
        }
        long n = std::atol(av[i]);
        if (n < 0 || n > INT_MAX) {
            std::cerr << "Error : Please enter integers between 0 and int_max." << std::endl;
            return;
        }
        _vector.push_back(static_cast<ElementType>(n));
        _deque.push_back(static_cast<ElementType>(n));
    }

    std::cout << "Before: ";
    for(size_t i = 0; i < _vector.size(); i++) {
        std::cout << _vector[i] << " ";
        if(i > 4) {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    #ifdef EVAL_MODE
    Number::cnt = 0;
    #endif
    SortVector(_vector);
    gettimeofday(&end, NULL);
    #ifdef EVAL_MODE
    std::cout << "Vector Comparisons: " << Number::cnt << std::endl;
    #endif
    long secs = end.tv_sec - start.tv_sec;
    long usecs = end.tv_usec - start.tv_usec;
    double VectTime = secs * 1000000.0 + usecs;
    gettimeofday(&start, NULL);
    #ifdef EVAL_MODE
    Number::cnt = 0;
    #endif
    SortDeque(_deque);
    gettimeofday(&end, NULL);
    #ifdef EVAL_MODE
    std::cout << "Deque Comparisons: " << Number::cnt << std::endl;
    #endif
    secs = end.tv_sec - start.tv_sec;
    usecs = end.tv_usec - start.tv_usec;
    double DequeTime = secs * 1000000.0 + usecs;
    std::cout << "After: ";
    for(size_t i = 0; i < _vector.size(); i++) {
        std::cout << _vector[i] << " ";
        if(i > 4) {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << VectTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << DequeTime << " us" << std::endl;
}

void PmergeMe::SortVector(std::vector<ElementType>& arr)
{
    if (arr.size() <= 1)
        return;
    bool hasStraggler = false;
    ElementType straggler;
    if (arr.size() % 2 != 0)
    {
        straggler = arr.back();
        hasStraggler = true;
        arr.pop_back();
    }
    std::vector<std::pair<ElementType, ElementType> > pairs;
    std::vector<ElementType> mainChain;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
            mainChain.push_back(arr[i]);
        } else {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
            mainChain.push_back(arr[i + 1]);
        }
    }
    SortVector(mainChain);
    std::vector<ElementType> pending;
    std::vector<size_t> winnerIndices;
	std::vector<bool> pairUsed(pairs.size(), false);
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        winnerIndices.push_back(i); 
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!pairUsed[j] && pairs[j].first == mainChain[i])
            {
                pending.push_back(pairs[j].second);
				pairUsed[j] = true;
                break;
            }
        }
    }
    if (hasStraggler)
    {
        pending.push_back(straggler);
        winnerIndices.push_back(mainChain.size()); 
    }
    mainChain.insert(mainChain.begin(), pending[0]);

    for (size_t k = 0; k < winnerIndices.size(); k++)
        winnerIndices[k]++;
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    for (size_t i = 2; ; i++)
    {
        size_t nextJ = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        jacobsthal.push_back(nextJ);
        if (nextJ >= pending.size())
            break;
    }
    size_t lastIndex = 0;
    for (size_t i = 1; i < jacobsthal.size(); i++)
    {
        size_t index = jacobsthal[i] - 1;
        if (index >= pending.size())
            index = pending.size() - 1;

        for (size_t j = index; j > lastIndex; j--)
        {
            ElementType loser = pending[j];
            size_t limitIndex = winnerIndices[j];
            std::vector<ElementType>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.begin() + limitIndex, loser);
            size_t insertPosIndex = std::distance(mainChain.begin(), pos);
            mainChain.insert(pos, loser);
            
            for (size_t k = 0; k < winnerIndices.size(); k++)
            {
                if (winnerIndices[k] >= insertPosIndex)
                    winnerIndices[k]++;
            }
        }
        lastIndex = index;
    }
    arr = mainChain;
}


void PmergeMe::SortDeque(std::deque<ElementType>& arr)
{
    if (arr.size() <= 1)
        return;
    bool hasStraggler = false;
    ElementType straggler;
    if (arr.size() % 2 != 0)
    {
        straggler = arr.back();
        hasStraggler = true;
        arr.pop_back();
    }
    std::deque<std::pair<ElementType, ElementType> > pairs;
    std::deque<ElementType> mainChain;

    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
            mainChain.push_back(arr[i]);
        } else {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
            mainChain.push_back(arr[i + 1]);
        }
    }
    SortDeque(mainChain);
    std::deque<ElementType> pending;
    std::deque<size_t> winnerIndices;
	std::deque<bool> pairUsed(pairs.size(), false);
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        winnerIndices.push_back(i); 
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!pairUsed[j] &&pairs[j].first == mainChain[i])
            {
                pending.push_back(pairs[j].second);
				pairUsed[j] = true;
                break;
            }
        }
    }
    if (hasStraggler)
    {
        pending.push_back(straggler);
        winnerIndices.push_back(mainChain.size()); 
    }
    mainChain.insert(mainChain.begin(), pending[0]);

    for (size_t k = 0; k < winnerIndices.size(); k++)
        winnerIndices[k]++;
    std::deque<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    for (size_t i = 2; ; i++)
    {
        size_t nextJ = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        jacobsthal.push_back(nextJ);
        if (nextJ >= pending.size())
            break;
    }
    size_t lastIndex = 0;
    for (size_t i = 1; i < jacobsthal.size(); i++)
    {
        size_t index = jacobsthal[i] - 1;
        if (index >= pending.size())
            index = pending.size() - 1;

        for (size_t j = index; j > lastIndex; j--)
        {
            ElementType loser = pending[j];
            size_t limitIndex = winnerIndices[j];
            std::deque<ElementType>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.begin() + limitIndex, loser);
            size_t insertPosIndex = std::distance(mainChain.begin(), pos);
            mainChain.insert(pos, loser);
            
            for (size_t k = 0; k < winnerIndices.size(); k++)
            {
                if (winnerIndices[k] >= insertPosIndex)
                    winnerIndices[k]++;
            }
        }
        lastIndex = index;
    }
    arr = mainChain;
}
