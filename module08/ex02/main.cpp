#include "MutantStack.hpp"
#include <cstdio>
#include <exception>
#include <iostream>
#include <list>

int subject_main_list() {
  std::list<int> mstack;
  mstack.push_back(5);
  mstack.push_back(17);
  std::cout << mstack.back() << std::endl;
  mstack.pop_back();
  std::cout << mstack.size() << std::endl;
  mstack.push_back(3);
  mstack.push_back(5);
  mstack.push_back(737);
  //[...]
  mstack.push_back(0);
  std::list<int>::iterator it = mstack.begin();
  std::list<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::list<int> s(mstack);
  return 0;
}


int subject_main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
  return 0;
}

int main(void) {
	std::cout << "------------------------" <<std::endl;
	subject_main();
	std::cout << "------------------------" <<std::endl;
	subject_main_list();
	std::cout << "------------------------" <<std::endl;
  MutantStack<int> a;

  a.push(10);
  a.push(11);
  a.push(12);
  a.push(13);

  //----------------------------------------------------//

  const MutantStack<int>::const_iterator const_it_begin = a.begin();
  const MutantStack<int>::const_iterator const_it_end = a.end();
  MutantStack<int>::iterator it_begin = a.begin();
  MutantStack<int>::iterator it_end = a.end();
  const MutantStack<int>::const_reverse_iterator const_reverse_it_begin =
      a.rbegin();
  MutantStack<int>::reverse_iterator reverse_it_begin = a.rbegin();
  const MutantStack<int>::const_reverse_iterator const_reverse_it_end =
      a.rend();
  MutantStack<int>::reverse_iterator reverse_it_end = a.rend();

  //----------------------------------------------------//

  ///////////////////////////
  //  const iterator begin //
  ///////////////////////////
  std::cout << "use cosnt iterator begin" << std::endl
            << *const_it_begin << std::endl;
  // std::cout << "try to change cosnt iterator begin" << *++const_it_begin <<
  // std::endl;

  ///////////////////////////
  //    iterator begin     //
  ///////////////////////////
  std::cout << "use iterator begin" << std::endl << *it_begin << std::endl;
  std::cout << "try to change iterator begin"; //<< std::endl << *it_begin <<
                                               //std::endl;

  while (it_begin != const_it_end) {
    std::cout << *it_begin << std::endl;
    it_begin++;
  }
  (void)it_end;

  ////////////////////////////////////
  //  const reverse iterator begin  //
  ////////////////////////////////////
  std::cout << "use cosnt reverse iterator begin" << std::endl
            << *const_reverse_it_begin << std::endl;
  // std::cout << "try to change cosnt reverse iterator begin" <<
  // *++const_reverse_it_begin << std::endl;

  ///////////////////////////////////
  //     reverse iterator begin    //
  ///////////////////////////////////
  std::cout << "use reverse iterator begin" << std::endl
            << *reverse_it_begin << std::endl;
  std::cout << "try to change reverse iterator begin" << std::endl
            << *++reverse_it_begin << std::endl;

  while (reverse_it_begin != const_reverse_it_end) {
    std::cout << *reverse_it_begin << std::endl;
    reverse_it_begin++;
  }
  (void)reverse_it_end;

  //----------------------------------------------------//
  return 0;
}
