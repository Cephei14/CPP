#include "Bureaucrat.hpp"

int main()
{
    // --- Test 1: Valid Bureaucrat ---
    std::cout << "--- TEST 1: Valid Bureaucrat ---" << std::endl;
    try
	{
        Bureaucrat bob	("Bob", 2);
        std::cout << bob << std::endl;

        std::cout << "Incrementing grade..." << std::endl;
        bob.increment();
        std::cout << bob << std::endl;

        std::cout << "Decrementing grade..." << std::endl;
        bob.decrement();
        std::cout << bob << std::endl;
    }
    catch (std::exception& e)
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // --- Test 2: Grade Too High in Constructor ---
    std::cout << "--- TEST 2: Grade Too High in Constructor (0) ---" << std::endl;
    try
	{
        Bureaucrat alice("Alice", 0);
    }
    catch (std::exception& e)
	{
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // --- Test 3: Grade Too Low in Constructor ---
    std::cout << "--- TEST 3: Grade Too Low in Constructor (151) ---" << std::endl;
    try
	{
        Bureaucrat john("John", 151);
    }
    catch (std::exception& e)
	{
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // --- Test 4: Grade Too High during Increment ---
    std::cout << "--- TEST 4: Incrementing Grade 1 ---" << std::endl;
    try
	{
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;
        
        std::cout << "Trying to increment..." << std::endl;
        boss.increment();
    }
    catch (std::exception& e)
	{
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // --- Test 5: Grade Too Low during Decrement ---
    std::cout << "--- TEST 5: Decrementing Grade 150 ---" << std::endl;
    try
	{
        Bureaucrat intern("Intern", 150);
        std::cout << intern << std::endl;

        std::cout << "Trying to decrement..." << std::endl;
        intern.decrement();
    }
    catch (std::exception& e)
	{
        std::cout << "Exception caught: " << e.what() << std::endl;
	}
    return 0;
}