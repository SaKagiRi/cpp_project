#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

		bool	ADD(void);
		bool	SEARCH(void);
	private:
		int		cur;
		Contact	book[8];
};

#endif
