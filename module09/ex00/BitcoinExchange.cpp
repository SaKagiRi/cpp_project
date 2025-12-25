#include "BitcoinExchange.hpp"
#include <stdexcept>

//Private member function
template<typename first, typename second>
std::pair<first, second> BitcoinExchange::lineToPair(std::string line, char sep)
{
	std::pair<first, second> res;
	size_t position = 0;

	position = line.find(sep);
	if (position == std::string::npos || line.rfind(sep) != position)
		throw(unexpected("Invalid file rule format => '"+line+"'"));

	std::istringstream left(line.substr(0, position));
	std::istringstream right(line.substr(position + 1));

	if (!(left >> res.first) || !(right >> res.second))
		throw(unexpected(ERR_DATATYPE_NOTMATCH));
	return (res);
}

void BitcoinExchange::clean(void)
{
	if (_fileDatabase.is_open())
		_fileDatabase.close();
	if (_fileInput.is_open())
		_fileInput.close();
	if (!_rate.empty())
		_rate.clear();
}

int dayInMonth(int year, int month)
{
	static int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	if (month == 2 && leap)
		return (29);
	return (day[month - 1]);
}

void BitcoinExchange::validateDate(std::string date)
{
	std::istringstream iss(date);
	int year, month, day;
	char dash1, dash2;
	
	if (date.length() != 10)
		throw(unexpected(ERR_DATE_FORMAT));
	if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
		throw(unexpected(ERR_DATE_FORMAT));
	if (year <= 0 || month <= 0 || day <= 0)
		throw(unexpected(ERR_DATE_LOW));
	if (year > 2030 || month > 12 || day > dayInMonth(year, month))
		throw(unexpected(ERR_DATE_UNREAL));
}

void BitcoinExchange::validateFile(std::string fileName, std::string fileType, std::fstream& file)
{
	if (fileName.find(fileType) == std::string::npos || \
		fileName.rfind(fileType) != fileName.length() - 4)
		throw(unexpected(ERR_FILETYPE" => " + fileName + " not " + fileType));
	if (file.is_open())
		file.close();
	if (fileName.empty())
		throw(unexpected(ERR_NO_FILENAME));
	file.exceptions(std::fstream::badbit);
	file.open(fileName.c_str(), std::ios::in);
	if (!file)
		throw(unexpected(ERR_NOT_OPENFILE));
}

void BitcoinExchange::readDatabase(void)
{
	std::string line;
	bool header = false;

	try{
		while (std::getline(_fileDatabase, line))
		{
			std::istringstream iss(line);
			std::pair<std::string, float> pair;
		
			if (line == "date,exchange_rate" && !header)
			{
				header = true;
				continue;
			}
			if (line.find(',') == std::string::npos)
				throw(unexpected(ERR_DATABASE_FORMAT));
			pair = lineToPair<std::string, float>(line, ',');
			validateDate(pair.first);
			if (_rate.count(pair.first) == 1)
				throw(unexpected(ERR_DATE_ALREADY_EXIST));
			_rate.insert(pair);
		}
	}catch(const std::exception& e)
	{
		std::cerr << "Database reading error: " << e.what() << std::endl;
	}
}

void BitcoinExchange::readInput(void)
{
	std::string line;
	bool header = false;

	while (std::getline(_fileInput, line))
	{
		std::istringstream iss(line);
		std::pair<std::string, float> pair;
		char c;

		if (!header)
		{
			std::pair<std::string, std::string> p;
			if (!(iss >> p.first >> c >> p.second) || p.first != "date" || p.second != "value" || c != '|')
				throw(unexpected(ERR_INPUT_HEADER));
			header = true;
			continue ;
		}
		try{
			if (!(iss >> pair.first >> c >> pair.second) || c != '|')
				throw(unexpected(ERR_INPUT_BAD" => " + line));
			validateDate(pair.first);
			if (pair.second < 0)
				throw(unexpected(ERR_INPUT_LOW));
			if (pair.second > 1000)
				throw(unexpected(ERR_INPUT_LARGE));
			printValue(pair);
		}catch(std::exception& e)
		{
			std::cerr << "Input validate error: " << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::printValue(std::pair<std::string, float> input)
{
	std::map<std::string, float>::iterator rate;
	float res = 0;

	if (input.first < _rate.begin()->first)
		throw(unexpected(ERR_INPUT_DATE_NO_RATE));
	if (_rate.count(input.first) == 0)
	{
		rate = _rate.lower_bound(input.first);
		if (rate != _rate.begin())
			rate--;
	}
	else
		rate = _rate.find(input.first);
	res = input.second * rate->second;
	std::cout << input.first << " => " << input.second << " = " << res << std::endl;
}

//Orthodox canonical form
BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::~BitcoinExchange(void)
{
	clean();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& source)
{
	_rate.insert(source._rate.begin(), source._rate.end());
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& source)
{
	if (this != &source)
		_rate.insert(source._rate.begin(), source._rate.end());
	return *this;
}

//Member fcuntion
void BitcoinExchange::setupDatabase(std::string databaseName)
{
	try{
		validateFile(databaseName, ".csv", this->_fileDatabase);
		readDatabase();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Database Error: " << e.what() << std::endl;
	}
}

void BitcoinExchange::processInput(std::string inputFile)
{
	try{
		if (!_fileDatabase.is_open() || _rate.empty())
			throw std::runtime_error("database not found");
		validateFile(inputFile, ".txt", this->_fileInput);
		readInput();

	}catch (const std::exception& e)
	{
		std::cerr << "Input error " << e.what() << std::endl;
	}
}

//Throw errro class
BitcoinExchange::unexpected::unexpected(std::string errorMsg)throw(): _errorMsg(errorMsg){} 
BitcoinExchange::unexpected::~unexpected(void)throw(){}
const char *BitcoinExchange::unexpected::what(void) const throw()
{
		return (_errorMsg.c_str());
};
