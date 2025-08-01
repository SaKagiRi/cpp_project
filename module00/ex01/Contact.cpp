#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
}

void	Contact::setNumber(std::string number)
{
	this->number = number;
}

void	Contact::setSecrets(std::string secrets)
{
	this->secrets = secrets;
}

std::string	Contact::getFirstName(void)
{
	return (this->firstName);
}

std::string	Contact::getLastName(void)
{
	return (this->lastName);
}

std::string	Contact::getNickName(void)
{
	return (this->nickName);
}
std::string	Contact::getNumber(void)
{
	return (this->number);
}
std::string	Contact::getSecrets(void)
{
	return (this->secrets);
}
