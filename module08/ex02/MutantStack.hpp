#pragma once
#include <iostream>

#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
	private:
	public:
		MutantStack(void):std::stack<T>() {}
		MutantStack(const MutantStack<T>& source):std::stack<T>(source) {}
		~MutantStack(void) {}
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	
	iterator begin()
	{ return (this->c.begin()); }

	const_iterator begin() const
	{ return (this->c.begin()); }

	iterator end()
	{ return (this->c.end()); }

	const_iterator end() const
	{ return (this->c.end()); }

	reverse_iterator rbegin()
	{ return (this->c.rbegin()); }

	const_reverse_iterator rbegin() const
	{ return (this->c.rbegin()); }

	reverse_iterator rend()
	{ 
		return (std::stack<T>::c.rend()); }

	const_reverse_iterator rend() const
	{ return (this->c.rend()); }
};

// --------------------------------------------------------------
// iterator
//   begin() _GLIBCXX_NOEXCEPT
//   { return this->_M_impl._M_start; }
//
//   const_iterator
//   begin() const _GLIBCXX_NOEXCEPT
//   { return this->_M_impl._M_start; }
//
//   iterator
//   end() _GLIBCXX_NOEXCEPT
//   { return this->_M_impl._M_finish; }
//
//   const_iterator
//   end() const _GLIBCXX_NOEXCEPT
//   { return this->_M_impl._M_finish; }
//
//   reverse_iterator
//   rbegin() _GLIBCXX_NOEXCEPT
//   { return reverse_iterator(this->_M_impl._M_finish); }
//
//   const_reverse_iterator
//   rbegin() const _GLIBCXX_NOEXCEPT
//   { return const_reverse_iterator(this->_M_impl._M_finish); }
//
//   reverse_iterator
//   rend() _GLIBCXX_NOEXCEPT
//   { return reverse_iterator(this->_M_impl._M_start); }
//
//   const_reverse_iterator
//   rend() const _GLIBCXX_NOEXCEPT
//   { return const_reverse_iterator(this->_M_impl._M_start); }
//
// --------------------------------------------------------------
//
//   const_iterator
//   cbegin() const noexcept
//   { return this->_M_impl._M_start; }
//
//   const_iterator
//   cend() const noexcept
//   { return this->_M_impl._M_finish; }
//
//   const_reverse_iterator
//   crbegin() const noexcept
//   { return const_reverse_iterator(this->_M_impl._M_finish); }
//
//   const_reverse_iterator
//   crend() const noexcept
//   { return const_reverse_iterator(this->_M_impl._M_start); }
// --------------------------------------------------------------
