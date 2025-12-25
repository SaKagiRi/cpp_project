#include "BitcoinExchange.hpp"

int main(int c, char **v) {
	BitcoinExchange btc;

	if (c != 2)
	{
		std::cout << "Usage: ./btc <file.txt>" << std::endl;
		return (1);
	}
	try{
		btc.setupDatabase("data.csv");
		btc.processInput(v[1]);
	}catch(std::exception& e)
	{
		std::cerr << "Program error: " << e.what() << std::endl;
	}
};
