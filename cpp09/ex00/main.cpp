#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	if (argc != 2)
	{
		std::cout << "Please provide a file" << std::endl;
		return (0);
	}
	std::string file = argv[1];
	Bitcoin btc("data.csv");
	btc.openFile();
	btc.calcValueMultiplied(file);
	return (0);
}