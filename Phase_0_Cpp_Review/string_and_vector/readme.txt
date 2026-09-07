1. string
std::string is C++'s standard type for storing text.

#include <string>

std::string name = "Alice";
name.size();       // number of characters
name.empty();      // true if empty
name[0];           // access character
name += " Smith";  // append

Modern C++ rule

For normal text, std::string should generally be your default choice.

2. vector
std::vector<T> is a dynamically sized array of T.

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    std::cout << numbers[0] << '\n';
    std::cout << numbers[1] << '\n';
    std::cout << numbers[2] << '\n';
    std::cout << numbers.size();
    numbers.empty();

    for (int number : numbers) is usually preferable when read
    {
        std::cout << number << '\n';
    }

    for (int& number : numbers)
    {
        number *= 2;
    }

    for (const int& number : numbers)
    {
        std::cout << number << '\n';
    }

    numbers.reserve(1000);
}

vector has capacity.
when vector is full, it copies/moves its element to another memory block with a larger capacity.
numbers.reserve(1000);

numbers.at(100)  performs bounds checking.
