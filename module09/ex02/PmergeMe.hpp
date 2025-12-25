#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <bits/types/struct_timeval.h>
# include <iostream>
#include <iterator>
# include <sstream>
# include <stdexcept>
# include <algorithm>
# include <limits>
# include <utility>
# include <vector>
# include <deque>
# include <list>
# include <sys/time.h>

# define RED    "\033[31m"
# define YELLOW "\033[33m"
# define RESET  "\033[0m"

bool isAllDigit(std::string& s);

template< template<typename _Tp, typename _Alloc = std::allocator<_Tp> >
class Container>
class PmergeMe
{
	private:
		typedef struct s_Pair{
			int min;
			int max;
			s_Pair(int _max, int _min)
			{
				min= _min;
				max= _max;
			}
		} Pair;
		typedef Container<int> Container_type;
		typedef Container<Pair> Chain;

	public:
		PmergeMe(void):time_flags(false) {}
		~PmergeMe(void) {}
		template< template<typename, typename>class OtherContainer>
		PmergeMe(const PmergeMe<OtherContainer>& p);
		template< template<typename, typename>class OtherContainer>
		PmergeMe& operator=(const PmergeMe<OtherContainer>& p);

		typename Container_type::const_iterator begin() const {return list.begin(); }
		typename Container_type::const_iterator end() const {return list.end(); }
		typename Container_type::iterator begin() {return list.begin(); }
		typename Container_type::iterator end() {return list.end(); }

		void printALlItem(void) const;

		bool is_sort(void);
		void sort(void);
		void insert(std::string);
		std::string getTime(void);
		size_t size(void) const { return list.size(); }

		timeval getTimeval(void) const { return time; }
		bool getTimeFlags(void) const { return time_flags; }

	private:
		Container_type list;
		timeval time;
		bool time_flags;

		void fordJohnsonSort(Container_type&, Container_type&);
		void parsInput(std::string);
		void timeStart(void);
		void timeStop(void);
};

template< template<typename, typename>class Container>
std::string PmergeMe<Container>::getTime(void)
{
	std::stringstream sec;
	std::stringstream usec;

	if (!time_flags)
		throw std::runtime_error("don't have record time.");
	if (time.tv_usec < 0)
	{
		time.tv_sec -= 1;
		time.tv_usec = 1000000 - time.tv_usec;
	}
	usec << time.tv_usec;
	sec << time.tv_sec << ".";
	for (size_t i = 0; i < 6 - usec.str().length(); i++)
		sec << "0";
	sec << usec.str();
	return sec.str();
}

template< template<typename, typename>class Container>
void PmergeMe<Container>::timeStart(void)
{
	gettimeofday(&time, NULL);
	time_flags = true;
}

template< template<typename, typename>class Container>
void PmergeMe<Container>::timeStop(void)
{
	timeval stop;

	if (!time_flags)
		return ;
	gettimeofday(&stop, NULL);
	time.tv_sec = stop.tv_sec - time.tv_sec;
	time.tv_usec = stop.tv_usec - time.tv_usec;
}

/**
 * @brief impliment template `template paramiter` coopy constructor class  
 * @paramiter can be other `PmergeMe<STL>` not same as this container
 * like `vector` `list` or `deque`  
 */
template< template<typename, typename>class Container>
template< template<typename, typename>class OtherContainer>
PmergeMe<Container>::PmergeMe(const PmergeMe<OtherContainer>& p)
{
	timeval temp_time = p.time;
	bool temp_flags = p.time_flags;

	this->list.insert(list.end(), p.begin(), p.end());
	time = temp_time;
	time_flags = temp_flags;
}

/**
 * @brief impliment template `template paramiter` operator=()
 * @paramiter can be other `PmergeMe<STL>` not same as this container
 * like `vector` `list` or `deque`  
 */
template< template<typename, typename>class Container>
template< template<typename, typename>class OtherContainer>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe<OtherContainer>& p)
{
	if ((void*)this != (void*)&p)
	{
		timeval temp_time = p.getTimeval();
		bool temp_flags = p.getTimeFlags();

		this->list.clear();
		this->list.insert(list.end(), p.begin(), p.end());
		time = temp_time;
		time_flags = temp_flags;
	}
	return (*this);
}

template< template<typename, typename>class Container>
void PmergeMe<Container>::printALlItem(void) const
{
	typename Container_type::const_iterator it = list.begin();
	for (;it != list.end(); it++)
	{
	  std::cout << *it << " ";
	}
	std::cout << std::endl;
}

/**
 * @brief parser string input that's must `positive number` only and less than `INT_MAX`
 * @paramiter `string number` seperate by `space`
 */
template< template<typename, typename>class Container>
void PmergeMe<Container>::parsInput(std::string input)
{
	std::stringstream ss(input);
	std::string token;
	int number;

	while (ss >> token)
	{
		if (isAllDigit(token))
		{
			std::stringstream atoi(token);
			atoi >> number;
			typename Container_type::iterator it = std::find(list.begin(), list.end(), number);
			if (it != list.end())
				throw std::runtime_error("number '" + atoi.str() + "' already exist.");
			list.push_back(number);
		}
		else
			throw std::runtime_error("Invalid input '" + token + "'.");
	}
}

/**
 * @brief helper function for alloc vector
 */
template< typename T>
void reserve(std::vector<T>& vec, size_t size)
{
	vec.reserve(size);
}

/**
 * @brief avoid helper when other container not vector
 */
template< typename Container>
void reserve(Container& cont, size_t size)
{
	(void)cont;
	(void)size;
}

/**
 * @brief merge-insert sort call Ford-Johnson sort
 * @algorithm
 *
 * - step1 group X element to `[ X / 2 ]` pairs
 *
 * - step2 find larger element of each pair
 *
 * - step3 recursive sort larger of each pair `[ X / 2 ]`
 *
 * - step4 insert pending on index befor max of each pair
 */
template< template<typename, typename>class Container>
void PmergeMe<Container>::fordJohnsonSort(Container_type& source, Container_type& sortList)
{
	Chain chain;
	bool have_straggler = (source.size() % 2 != 0);
	int straggler = 0;

	if (source.size() <= 1)
	{
		sortList.push_back(source.back());
		return ;
	}
	reserve(chain, source.size() / 2);

	//--step1-- pair min max
	if (have_straggler)
		straggler = source.back();
	for (typename Container_type::iterator it = source.begin(); std::distance(it, source.end()) > 1; std::advance(it, 2))
	{
		typename Container_type::iterator second = it;
		std::advance(second, 1);
		if (*it > *second)
			chain.push_back(Pair(*it, *second));
		else
			chain.push_back(Pair(*second, *it));
	}
	
	//--step2-- recursive half
	Container_type main;
	reserve(main, source.size() / 2);
	for (typename Chain::iterator it = chain.begin(); it != chain.end(); it++)
		main.push_back(it->max);

	fordJohnsonSort(main, sortList);

	//--step3-- insert pending and straggler use jacobsthal sequence
	if (have_straggler)
	{
		typename Container_type::iterator pos = std::lower_bound(sortList.begin(), sortList.end(), straggler);
		sortList.insert(pos, straggler);
	}
	// 0 2 1 4 3 9 8 7 6 5
	// 0 -> 2  = 2 - 0 = +2;
	// 2 -> 1 = 1 - 2 = -1;
	// curr -> next = next - curr = distance;
	// and loopback;
	size_t prev = 0;
	size_t curr = 1;
	size_t proc = 0;
	size_t temp_limit = 0;
	typename Chain::iterator it = chain.begin();
	while (proc < chain.size())
	{
		size_t limit = curr;
		if (limit > chain.size())
			limit = chain.size();
		while (limit > proc)
		{
			if (it == chain.end())
				it--;
			typename Container_type::iterator max_it = std::lower_bound(sortList.begin(), sortList.end(), it->max);
			typename Container_type::iterator pos = std::lower_bound(sortList.begin(), max_it, it->min);
			sortList.insert(pos, it->min);
			std::advance(it, limit - temp_limit);
			temp_limit = limit;
			limit--;
		}
		proc = curr;
		size_t next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
}

template< template<typename, typename>class Container>
bool PmergeMe<Container>::is_sort(void)
{
	for (typename Container_type::iterator it = list.begin(); it != list.end(); it++)
	{
		typename Container_type::iterator next = it;
		std::advance(next, 1);
		if (next == list.end())
			break ;
		if (!(*next > *it))
			return (false);
	}
	return (true);
}

template< template<typename, typename>class Container>
void PmergeMe<Container>::sort(void)
{
	Container_type already_sort;

	if (list.size() <= 1)
		throw std::runtime_error("can not sort less than 2 number.");
	if (is_sort())
		throw std::runtime_error("it's already sorted.");

	timeStart();
	reserve(already_sort, list.size());
	fordJohnsonSort(list, already_sort);
	timeStop();

	list = already_sort;
}

template< template<typename, typename>class Container>
void PmergeMe<Container>::insert(std::string input)
{
	parsInput(input);
}

#endif
