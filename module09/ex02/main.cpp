#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error: No arguments provided." << std::endl;
        return 1;
    }

    PmergeMe sorter;
    sorter.Start(ac, av);

    return 0;
}