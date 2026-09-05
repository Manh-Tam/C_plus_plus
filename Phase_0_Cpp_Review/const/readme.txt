const in C++ represents constant data.

C++ uses
const and constexpr
const is evaluated at runtime.

constexpr is evaluated at compile time.
For example
{
    constexpr int width = 3;
    constexpr int height = 5;
    constexpr int area = width * height;
}
might become
{
    constexpr int area = 3 * 5;
}
after compile time.


Global const data is often stored in read-only memory.
Local const data is often stored in stack.
Global constexpr data is often stored in read-only memory.
Local constexpr data is often optimized.

Of course, we can use #define in C++. However, const and constexpr are prefered due to their properties.

Common usage of const variables:
// 1. A value that shouldn't change
const int age = 20;

// 2. Don't modify an object passed to a function
void print(const Person& person);

// 3. A member function that doesn't modify the object
int getAge() const;