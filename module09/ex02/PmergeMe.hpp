#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <utility>
#include <sys/time.h>

class PmergeMe
{
private:
    std::vector<int> _vector;
    std::deque<int> _deque;

    void SortVector(std::vector<int>& vct);
    void SortDeque(std::deque<int>& dq);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void Start(int ac, char **av);
};

#endif