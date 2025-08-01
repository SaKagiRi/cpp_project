#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->cur = 0;
}

PhoneBook::~PhoneBook(void)
{
}

static bool getWord(std::string word, std::string &input)
{
	std::string	line;

	while (1)
	{
		std::cout << word;
		if (!std::getline(std::cin, line))
			return (1);
		if (line != "")
			break ;
	}
	input = line;
	return (0);
}

bool	PhoneBook::ADD(void)
{
	Contact		*node;
	std::string	input;
	bool		err;

	node = &this->book[this->cur % 8];
	err = 0;
	err = getWord("FirstName: ", input);
	if (err)
		return (1);
	node->setFirstName(input);

	err = getWord("LastName: ", input);
	if (err)
		return (1);
	node->setLastName(input);

	err = getWord("NickName: ", input);
	if (err)
		return (1);
	node->setNickName(input);

	err = getWord("Phone Number: ", input);
	if (err)
		return (1);
	node->setNumber(input);

	err = getWord("Darkest Secrets: ", input);
	if (err)
		return (1);
	node->setSecrets(input);

	this->cur++;
	if (this->cur == 8)
		this->cur = 0;
	return (0);
}

static void	printOneContact(Contact contact)
{
	int				i;
	int				j;
	std::string		content;

	i = 0;
	std::cout << "|";
	while (i < 3)
	{
		j = 0;
		if (i == 0)
			content = contact.getFirstName();
		else if (i == 1)
			content = contact.getLastName();
		else
			content = contact.getNickName();
		if (content.length() == 10)
			std::cout << content;
		else
		{
			if (content.length() < 10)
			{
				j = content.length();
				while (j++ < 10)
					std::cout << " ";
				std::cout << content;
			}
			else
			{
				while (j < 9)
					std::cout << content[j++];
				std::cout << ".";
			}
		}
		std::cout << "|";
		i++;
	}
	std::cout << std::endl;
}

static void	printAllBook(Contact book[8])
{
	int		i;

	i = 0;
	std::cout << " -------------------------------------" << std::endl;
	std::cout << "|index| firstname| lastname | nickname |" << std::endl;
	std::cout << " -------------------------------------" << std::endl;
	while(i < 8)
	{
		std::cout << "|   " << i + 1 << ".";
		printOneContact(book[i]);
		i++;
		std::cout << " -------------------------------------" << std::endl;
	}
}

static void	printFullContact(Contact contact)
{
	int		i;

	i = 0;
	if (contact.getFirstName() == "")
	{
		std::cout << "Nothing." << std::endl;
		return ;
	}
	while (i < 5)
	{
		if (i == 0)
			std::cout << "FirstName: " << contact.getFirstName() << std::endl;
		else if (i == 1)
			std::cout << "LastName: " << contact.getLastName() << std::endl;
		else if (i == 2)
			std::cout << "NickName: " << contact.getNickName() << std::endl;
		else if (i == 3)
			std::cout << "Number: " << contact.getNumber() << std::endl;
		else if (i == 4)
			std::cout << "Darkest Secrets: " << contact.getSecrets() << std::endl;
		i++;
	}
}

bool	PhoneBook::SEARCH(void)
{
	std::string	line;

	printAllBook(this->book);
	while (1)
	{
		std::cout << "SEARCH >> ";
		if (!std::getline(std::cin, line))
			return (1);
		if (line.length() == 1 && (line.at(0) - '0' < 9 && line.at(0) - '0' > 0))
			printFullContact(this->book[line.at(0) - '0' - 1]);
		else
		{
			std::cout << "SEARCH option '" << line << "' not found\n";
			return (1);
		}
	}
	return (0);
}
