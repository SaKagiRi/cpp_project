#pragma once

#include <iostream>

template <typename t_arr, typename t_func>
void iter(t_arr *arr, const size_t size, t_func function) {
  for (size_t i = 0; i < size; i++)
    function(arr[i]);
}
