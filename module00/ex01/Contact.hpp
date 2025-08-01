#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact{
	public:
		Contact();
		~Contact();

		void	setFirstName(std::string firstName);
		void	setLastName(std::string lastName);
		void	setNickName(std::string nickName);
		void	setNumber(std::string number);
		void	setSecrets(std::string secrets);

		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		std::string getNumber(void);
		std::string getSecrets(void);
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	number;
		std::string	secrets;
};

#endif
