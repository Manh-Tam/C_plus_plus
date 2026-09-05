#include <iostream>
#include <cstring>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

float add(float a, float b)
{
    return a + b;
}

int main()
{
    /*use add with int*/
    int num1 = 3;
    int num2 = 4;
    cout << add(num1, num2) << endl;

    /*use add with float*/
    float num3 = 3.5;
    float num4 = 5;
    cout << add(num3, num4) << endl;

    /*invalid usage*/
    // cout << add(num1, num3) << endl;

    return 0;
}