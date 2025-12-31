#include "iter.hpp"

template <typename T>
void print(T& n)
{
    std::cout << n << " ";
}

void increment(int& n)
{
    n++;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = 5;

    std::cout << "Original: ";
    ::iter(arr, len, print<int>);
    std::cout << std::endl;
    std::cout << "Incremented : ";
    ::iter(arr, len, increment);
    ::iter(arr, len, print<int>);
    std::cout << std::endl;
	
    std::string strs[] = {"Hello", "42", "Tokyo"};
    std::cout << "Strings: ";
    ::iter(strs, 3, print<std::string>);
    std::cout << std::endl;

    return 0;
}