#ifndef PMERGEME_HPP
#define PMERGEME_HPP

//#define EVAL_MODE

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

#ifdef EVAL_MODE
class Number {
public:
    static int cnt;
    int value;

    Number(int v = 0) : value(v) {} // Default + Value constructor

    bool operator<(const Number& other) const { cnt++; return value < other.value; }
    bool operator>(const Number& other) const { cnt++; return value > other.value; }
    bool operator==(const Number& other) const { return value == other.value; }
    bool operator!=(const Number& other) const { return value != other.value; }

    friend std::ostream& operator<<(std::ostream& os, const Number& n) {
        os << n.value;
        return os;
    }
};
typedef Number ElementType;
#else
typedef int ElementType;
#endif

class PmergeMe
{
private:
    std::vector<ElementType> _vector;
    std::deque<ElementType> _deque;
    void SortVector(std::vector<ElementType>& vct);
    void SortDeque(std::deque<ElementType>& dq);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void Start(int ac, char **av);
};

#endif