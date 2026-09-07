#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);

    for (int i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::string my_name = "Tam Le";
    std::cout << my_name << std::endl;
    for (char i : my_name)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}