#include <iostream>
#include <memory>


int main()
{
    int *p = new int(3);
    std::cout << *p << std::endl;
    delete p;

    auto smart_p = std::make_unique<int>(5);
    std::cout << *smart_p << std::endl;

    return 0;
}