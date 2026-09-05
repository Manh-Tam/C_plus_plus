#include <iostream>

struct Point
{
    int x;
    int y;
};

int main()
{
    Point point{3, 4};
    
    std::cout << point.x << ' ' << point.y << std::endl;

    return 0;
}