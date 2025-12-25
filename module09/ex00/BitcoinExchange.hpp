#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <cstdlib>
# include <cmath>
# include <exception>
# include <fstream>
# include <map>

//error
# define ERR_DATE_FORMAT "not valid date format: y-m-d"
# define ERR_DATE_LOW "all number of date must larger than zero"
# define ERR_DATE_UNREAL "date is not exist"
# define ERR_DATE_ALREADY_EXIST "date is already exist"
# define ERR_FILETYPE "filetype it's not correct"
# define ERR_NO_FILENAME "no have file name"
# define ERR_NOT_OPENFILE "cannot open file"
# define ERR_DATABASE_FORMAT "database must have date,rate"
# define ERR_DATATYPE_NOTMATCH "datatype not match in 'string', 'float'"
# define ERR_INPUT_HEADER "inputfile must have header 'date | value'"
# define ERR_INPUT_LARGE "too large a number."
# define ERR_INPUT_LOW "not a positive number."
# define ERR_INPUT_BAD "bad input."
# define ERR_INPUT_DATE_NO_RATE "this date no have rate."

class BitcoinExchange
{
	private:
		std::map<std::string, float> _rate;
		std::fstream _fileInput;
		std::fstream _fileDatabase;

		void validateDate(std::string);
		void validateFile(std::string fname, std::string ftype, std::fstream& f);
		void readDatabase(void);
		void readInput(void);
		void printValue(std::pair<std::string, float>);
		template<typename first_type, typename second_type>
		std::pair<first_type, second_type> lineToPair(std::string, char);
		void clean(void);

		class unexpected: public std::exception
		{
			private:
				std::string _errorMsg;
				unexpected(void);
			public:
				unexpected(std::string) throw();
				~unexpected(void)throw();
				const char *what( void ) const throw();
		};

	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);

		void setupDatabase(std::string);
		void processInput(std::string);
};

int dayInMonth(int year, int month);

#endif
