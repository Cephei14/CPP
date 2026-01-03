#include "MutantStack.hpp"
#include <fstream>
#include <list>

int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop(); 
        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;

        std::ofstream outfile("mutant_data.txt");
        if (!outfile.is_open())
        {
            std::cerr << "Error : could not open file!" << std::endl;
            return 1;
        }
        while (it != ite)
        {
            outfile << *it << std::endl;
            ++it;
        }
        outfile.close();
        std::cout << "Data written to mutant_data.txt" << std::endl;
        
        std::stack<int> s(mstack); 
    }

    {
        std::list<int> mylist;
        mylist.push_back(5);
        mylist.push_back(17);
        std::cout << mylist.back() << std::endl;
        mylist.pop_back();
        std::cout << mylist.size() << std::endl;

        mylist.push_back(3);
        mylist.push_back(5);
        mylist.push_back(737);
        mylist.push_back(0);

        std::list<int>::iterator it = mylist.begin();
        std::list<int>::iterator ite = mylist.end();

        ++it;
        --it;

        std::ofstream outfile("list_data.txt");
        if (!outfile.is_open())
        {
            std::cerr << "Error : could not open file!" << std::endl;
            return 1;
        }
        while (it != ite)
        {
            outfile << *it << std::endl;
            ++it;
        }
        outfile.close();
        std::cout << "Data written to list_data.txt" << std::endl;
    }

    return 0;
}