#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data("File", 1494);
	Data* dataptr = &data;

	std::cout << "Pointer's adress: " << dataptr << std::endl;
	std::cout << "Name: " << data.getName() << std::endl;
	std::cout << "Number:  " << dataptr->getNumber() << std::endl;
	
	uintptr_t raw = Serializer::serialize(dataptr);
	std::cout << "Raw's value: " << raw << std::endl;
	
	Data* reptr = Serializer::deserialize(raw);
	std::cout << "Restaured ptr's value: " << reptr << std::endl;
	std::cout << "Name: " << reptr->getName() << std::endl;
	std::cout << "Number: " << reptr->getNumber() << std::endl;

	return 0;
}