#include <iostream>

class A
{
	private:
		std::string _name;
	
	public:
		A();
		A(const A &other);
		
		~A();
};