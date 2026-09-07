1. Dynamic memory
In C++
std::vector
std::string
std::unique_ptr
are usually used than new and delete

dynamic memory are allocated at runtime.

2. Dynamic arrays
allocation
    int *numbers = new int[100];
access
    numbers[0]
    numbers[33]
deallocation
    delete[] numbers;

=> new T <=> delete
=> new T[100] <=> delete[]

3. RAII
Resouce allocation is initialization.
Instead of:
Person* p = new Person{"Alice", 25};
use:
auto p = std::make_unique<Person>("Alice", 25);
to be safer since heap memory belongs to p existing until p is destroyed.

4. std::unique_ptr
#include <memory>

auto person = std::make_unique<Person>("Alice", 25);


5. std::shared_ptr
auto p1 = std::make_shared<Person>("Alice", 25);
auto p2 = p1;

the object is destroyed when the last shared_ptr owning it disappears.

=> prefer unique_ptr
=> use shared_ptr when required.

6. Dynamic array 
use std::vector
since vector automatically deallocates memory
Instead of:
int *p = new int[100];
delete[] p;

use:
std::vector<int> numbers(n);
numbers[0] = 10;
numbers.push_back(20);
numbers.size();

7. rule of thumb
Need an object?
        ↓
    T object;

Need a dynamic collection?
        ↓
    std::vector<T>

Need dynamically owned single object?
        ↓
    std::unique_ptr<T>

Need shared ownership?
        ↓
    std::shared_ptr<T>

Need non-owning access?
        ↓
    T& or T*


