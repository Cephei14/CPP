#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
    std::cout << "--- CREATING ANIMAL ARRAY ---\n" << std::endl;
    const int num_animals = 4;
    Animal* animals[num_animals];

    for (int i = 0; i < num_animals / 2; i++)
    {
        std::cout << "Creating Dog " << i << std::endl;
        animals[i] = new Dog();
    }
    for (int i = num_animals / 2; i < num_animals; i++)
    {
        std::cout << "Creating Cat " << i << std::endl;
        animals[i] = new Cat();
    }

    std::cout << "\n--- DELETING ANIMAL ARRAY ---\n" << std::endl;
    for (int i = 0; i < num_animals; i++)
    {
        std::cout << "Deleting Animal " << i << std::endl;
        delete animals[i];
    }
    std::cout << std::endl;


    std::cout << "\n--- TESTING DEEP COPY ---\n" << std::endl;
    std::cout << std::endl;
	Dog original_dog;

	original_dog.getBrain()->set_idea(0, "I am the original dog");
	std::cout << "Original dog's first idea: \"" << original_dog.getBrain()->get_idea(0) << "\"" << std::endl;

	Dog copy_dog = original_dog;
	std::cout << "Copied dog's first idea: \"" << copy_dog.getBrain()->get_idea(0) << "\"" << std::endl;

	original_dog.getBrain()->set_idea(0, "My idea has changed");
	std::cout << "Original dog's NEW first idea: \"" << original_dog.getBrain()->get_idea(0) << "\"" << std::endl;

	std::cout << "Copied dog's idea : \"" << copy_dog.getBrain()->get_idea(0) << "\"" << std::endl;

    std::cout << "--- END OF PROGRAM ---\n" << std::endl;
    return 0;
}
