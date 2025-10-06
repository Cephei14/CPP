#include "main.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage <filename> <s1> <s2>\n";
		return 1;
	}

	std::string output_file;
	output_file = std::string(av[1]) + ".replace";

	std::ifstream input;
	input.open(av[1]);
	if(!input.is_open())
		return 1;

	std::ofstream output;
	output.open(output_file.c_str());
	if(!output.is_open())
		return 1;

	size_t pos;
	std::string line;
	std::string s1 = av[2];
	if(s1.empty())
		return 1;
	std::string s2 = av[3];
	while(std::getline(input, line))
	{
		pos = 0;
		while((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		output << line << std::endl;
	}
	input.close();
	output.close();
	return 0;
}
