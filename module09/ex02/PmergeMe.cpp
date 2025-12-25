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

size_t jacobsthal_sequence(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal_sequence(n - 1) + 2 * jacobsthal_sequence(n - 2);
}

size_t jacobsthal_sequence2(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    size_t prev2 = 0;
    size_t prev1 = 1;
    size_t curr = 0;

    for (size_t i = 2; i <= n; ++i)
    {
        curr = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
