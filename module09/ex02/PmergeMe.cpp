#include "PmergeMe.hpp"

bool isAllDigit(std::string& s)
{
	std::stringstream ss(s);
	long temp;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!(s.at(i) >= '0' && s.at(i) <= '9'))
			return false;
	}
	ss >> temp;
	if (temp > std::numeric_limits<int>::max())
		return false;
	return true;
}
