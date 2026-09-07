In C++, stack and heap are relevant to storage duration.
stack means automatic lifetime.
heap means dynamic lifetime.

local variables inside a function are destroyed when the program reaches the end of the funtion.

Traditional C++ uses new and delete to allocate and deallocate dynamic memory in heap.
the basic difference between stack and heap is lifetime.
stack stores local variables which are destroyed automatically.
heap allows data to exist until it is deallocated.

Fun fact:
int *p = new int(4);
p is stored in stack.
new int(4) is store in heap.

Modern C++ uses smart pointers.
Ex:
auto player = std::make_unique<Player>("Alice", 100);
to manage dynamic variables automatically.
player is deallocated when player goes out of scope.

vector uses the same mechanism.
vector is a struct with a pointer to heap.
vector is deallocated when vector goes out of scope.

std::string is the same.
it might use stack to create short strings and use heap for long strings.

it's a best practice to use vector for huge allocations.
std::vector<int> vector(1000000);
