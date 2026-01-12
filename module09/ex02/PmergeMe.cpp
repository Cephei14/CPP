#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	//std::cout<<"Default constructor called"<< std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque)
{
	//std::cout<<"Copy constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	//std::cout << "Destructor called" << std::endl; 
}

void PmergeMe::Start(int ac, char **av)
{
	for(int i = 1; i < ac; i++)
	{
		std::string str = av[i];
		for(size_t j = 0; j < str.length(); j++)
		{
			if(!isdigit(str[j]))
			{
				std::cerr << "Error : please enter a positive number." << std::endl;
				return;
			}
		}
		long n = std::atol(av[i]);
		if (n < 0 || n > INT_MAX)
		{
			std::cerr << "Error : Please enter integers between 0 and int_max(2147483647)." << std::endl;
			return;
		}
		_vector.push_back(static_cast<int>(n));
		_deque.push_back(static_cast<int>(n));
	}
	std::cout << "Before: ";
	for(size_t i = 0; i < _vector.size(); i++)
	{
		std::cout << _vector[i] << " ";
		if(i > 4)
		{
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
	struct timeval start, end;
	gettimeofday(&start, NULL);
	SortVector(_vector);
	gettimeofday(&end, NULL);
	long secs = end.tv_sec - start.tv_sec;
	long usecs = end.tv_usec - start.tv_usec;
	double VectTime = secs * 1000000.0 + usecs;
	gettimeofday(&start, NULL);
	SortDeque(_deque);
	gettimeofday(&end, NULL);
	secs = end.tv_sec - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
	double DequeTime = secs * 1000000.0 + usecs;

	std::cout << "After: ";
	for(size_t i = 0; i <_vector.size(); i++)
	{
		std::cout << _vector[i] << " ";
		if(i > 4)
		{
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << VectTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << DequeTime << " us" << std::endl;
}

void PmergeMe::SortVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return;
    // 1. Store actual pairs locally so we don't lose track!
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;
    // Handle Straggler
    if (arr.size() % 2 != 0)
    {
        straggler = arr.back();
        hasStraggler = true;
        arr.pop_back(); // Remove it temporarily
    }
    // 2. Create Pairs and Fill 'Main' (Winners)
    std::vector<int> mainChain;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        int n1 = arr[i];
        int n2 = arr[i + 1];

        if (n1 > n2)
        {
            pairs.push_back(std::make_pair(n1, n2));
            mainChain.push_back(n1);
        }
        else
        {
            pairs.push_back(std::make_pair(n2, n1));
            mainChain.push_back(n2);
        }
    }
    SortVector(mainChain);
    // 4. THE FIX: Re-build 'Pend' (Losers) to match the new sorted 'mainChain'
    std::vector<int> pending;
    // For every winner in the NOW SORTED mainChain...
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        int currentWinner = mainChain[i];
        // ... find its original loser in our 'pairs' list
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].first == currentWinner)
            {
                pending.push_back(pairs[j].second);
                break; // Found the partner, stop looking
            }
        }
    }
    // STEP 4: INSERTION LOGIC (The "Main Event")
    // 1. Insert the very first pending element (pending[0])
    // It is guaranteed to be smaller than mainChain[0] because mainChain[0] was its partner.
    mainChain.insert(mainChain.begin(), pending[0]);
    // Keep track of how many items we've added to update indices
    size_t addedCount = 1; 
    // 2. Generate Jacobsthal Sequence
    // We need indices like: 1, 3, 5, 11, 21, 43...
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    // Generate enough numbers to cover the size of pending
    // Formula: J(n) = J(n-1) + 2 * J(n-2)
    for (size_t i = 2; ; i++)
    {
        size_t nextJ = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        jacobsthal.push_back(nextJ);
        if (nextJ >= pending.size())
            break;
    }
    // 3. Loop through Jacobsthal groups
    size_t lastIndex = 0; // We already processed index 0 (the first loser)

    for (size_t i = 1; i < jacobsthal.size(); i++)
    {
        // Determine the range for this group
        // If the Jacobsthal number is bigger than our list, cap it.
        size_t index = jacobsthal[i] - 1;
        if (index >= pending.size())
            index = pending.size() - 1;

        // Iterate BACKWARDS from 'index' down to 'lastIndex + 1'
        // This is the "Jump and Walk Back" logic
        for (size_t j = index; j > lastIndex; j--)
        {
            int loser = pending[j];
            
            // OPTIMIZATION:
            // We only need to search up to the partner's location.
            // The partner (mainChain[j]) is currently at index: j + addedCount.
            // This limits the Binary Search range significantly.
            size_t boundIndex = j + addedCount; 
            
            // Standard Binary Search (std::lower_bound)
            std::vector<int>::iterator pos = std::lower_bound(
                mainChain.begin(), 
                mainChain.begin() + boundIndex, // Look only in the safe zone
                loser
            );

            mainChain.insert(pos, loser);
            addedCount++;
        }
        
        lastIndex = index; // Move the "done" marker forward
    }
    // STEP 5: HANDLE STRAGGLER (If any)
    if (hasStraggler)
    {
        std::vector<int>::iterator pos = std::lower_bound(
            mainChain.begin(), 
            mainChain.end(), 
            straggler
        );
        mainChain.insert(pos, straggler);
    }
    // STEP 6: FINALIZE
    arr = mainChain; // Copy the sorted result back to the original vector
}

void PmergeMe::SortDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1)
        return;
    // 1. Store actual pairs locally so we don't lose track!
    std::deque<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;
    // Handle Straggler
    if (arr.size() % 2 != 0)
    {
        straggler = arr.back();
        hasStraggler = true;
        arr.pop_back(); // Remove it temporarily
    }
    // 2. Create Pairs and Fill 'Main' (Winners)
    std::deque<int> mainChain;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        int n1 = arr[i];
        int n2 = arr[i + 1];

        if (n1 > n2)
        {
            pairs.push_back(std::make_pair(n1, n2));
            mainChain.push_back(n1);
        }
        else
        {
            pairs.push_back(std::make_pair(n2, n1));
            mainChain.push_back(n2);
        }
    }
    SortDeque(mainChain);
    // 4. THE FIX: Re-build 'Pend' (Losers) to match the new sorted 'mainChain'
    std::deque<int> pending;
    // For every winner in the NOW SORTED mainChain...
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        int currentWinner = mainChain[i];
        // ... find its original loser in our 'pairs' list
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].first == currentWinner)
            {
                pending.push_back(pairs[j].second);
                break; // Found the partner, stop looking
            }
        }
    }
    // 1. Insert the very first pending element (pending[0])
    // It is guaranteed to be smaller than mainChain[0] because mainChain[0] was its partner.
    mainChain.insert(mainChain.begin(), pending[0]);
    // Keep track of how many items we've added to update indices
    size_t addedCount = 1; 
    // 2. Generate Jacobsthal Sequence
    // We need indices like: 1, 3, 5, 11, 21, 43...
    std::deque<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    // Generate enough numbers to cover the size of pending
    // Formula: J(n) = J(n-1) + 2 * J(n-2)
    for (size_t i = 2; ; i++)
    {
        size_t nextJ = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        jacobsthal.push_back(nextJ);
        if (nextJ >= pending.size())
            break;
    }
    // 3. Loop through Jacobsthal groups
    size_t lastIndex = 0; // We already processed index 0 (the first loser)
    for (size_t i = 1; i < jacobsthal.size(); i++)
    {
        // Determine the range for this group
        // If the Jacobsthal number is bigger than our list, cap it.
        size_t index = jacobsthal[i] - 1;
        if (index >= pending.size())
            index = pending.size() - 1;
        // Iterate BACKWARDS from 'index' down to 'lastIndex + 1'
        // This is the "Jump and Walk Back" logic
        for (size_t j = index; j > lastIndex; j--)
        {
            int loser = pending[j];
            // OPTIMIZATION:
            // We only need to search up to the partner's location.
            // The partner (mainChain[j]) is currently at index: j + addedCount.
            // This limits the Binary Search range significantly.
            size_t boundIndex = j + addedCount; 
            // Standard Binary Search (std::lower_bound)
            std::deque<int>::iterator pos = std::lower_bound(
                mainChain.begin(), 
                mainChain.begin() + boundIndex, // Look only in the safe zone
                loser
            );
            mainChain.insert(pos, loser);
            addedCount++;
        }
        lastIndex = index; // Move the "done" marker forward
    }
    // STEP 5: HANDLE STRAGGLER (If any)
    if (hasStraggler)
    {
        std::deque<int>::iterator pos = std::lower_bound(
            mainChain.begin(), 
            mainChain.end(), 
            straggler
        );
        mainChain.insert(pos, straggler);
    }
    // STEP 6: FINALIZE
    arr = mainChain; // Copy the sorted result back to the original vector
}
