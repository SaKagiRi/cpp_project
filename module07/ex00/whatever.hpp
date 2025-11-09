#pragma once

#include <iostream>

template <typename t> void swap(t &a, t &b) {
  t temp;

  temp = a;
  a = b;
  b = temp;
}

template <typename t> t min(t a, t b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename t> t max(t a, t b)
{
	if (a > b)
		return (a);
	return (b);
}
