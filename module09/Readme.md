# CPP09

__Goal:__ learning STL and impliment with algorythm to solve a medium problem  
STL you should learn is:

- map
- queue and dqueue
- stack
- vector

## STL

__What is STL:__  a functional template class that helpful, together with
`container`, `algorythm`, and `iterator` for optimize your code.

### std::map

container store pair element that contain a key:value,
and the kay must be uniqe like  

```cpp
{[1: 'a'], [2: 'b'], [3: 'c']}
```

import fucntion from map library:

```cpp
#include <map>
```

member function:

- iterator
  - begin()
  - end()
  - rbegin()
  - rend()
- capacity
  - empty()
  - size()
  - max_size()
- access
  - operator\[ const key_type& \]
  - at( const key_type& )
- modifiers
  - insert()

  ```cpp
    map.insert( std::pair<key_type, value_type>(key, value) );
    map.insert( iterator position, const value_type& value );
    map.insert( iterator first, iterator last );
  ```

  - erase()

  ```cpp
    map.erase(iterator position);
    map.erase(const key_type& k);
    map.erase(iterator first, iterator last);
  ```

  - swap()

  ```cpp
  map.swap( another_map );
  ```

  - clear()
- opeartion
  - find( const key_type& )
  - count( cosnt key_type& )
  - lower_bound( const key_type& )
  - upper_bound( const key_type& )

---

### std::pair

class template that store 2 type object as a `single unit`

define:

```cpp
std::pair<T_first, T_second> pair;
```

access by `.first` and `.second` like:

```cpp
pair.first = "one";
pair.second = "two";
```

---

### std::stack

STL store value `first in fitst out` use `.top` to read top of stack
and `.push()` to inseart `.pop()` to delete top

import from:

```cpp
#include <stack>
```

define:

```cpp
std::stack<T> stack;
```

useage:

```cpp
std::stack<int> _stack;
_stack.push(10);
_stack.push(20);
std::cout << _stack.top() << std::endl; // 20
_stack.pop();
std::cout << _stack.top() << std::endl; // 10
```

---
