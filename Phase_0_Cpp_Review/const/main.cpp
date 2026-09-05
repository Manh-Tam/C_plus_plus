#include <iostream>
#include <string>

using namespace std;

/*1. constant data */
const float pi = 3.14;

/*2. an object shouldn't be modified*/
void print_string(const string& str)
{
    cout << str << endl;
}

/*3. Getter and accessor in Class*/
/* mean shouldn't modify class member value inside getter and accessor*/
class Person
{
private:
    string name;
    int age;
public:
    string getName() const
    {
        return name;
    }
    bool isAdult() const
    {
        return age >= 18;
    }

};

int main()
{
    float radius = 3;
    float area = radius * radius * pi;
    cout << area << endl;
    return 0;
}