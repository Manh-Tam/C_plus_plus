#include <iostream>

class Employee
{
private:
    std::string name_;
    int salary_;
public:
    Employee(const std::string& name, const int& salary)
    : name_(name), salary_(salary)
    {
        if (name.empty())
        {
            throw std::invalid_argument("Employee name cannot be empty");
        }
        if (salary < 0)
        {
            throw std::invalid_argument("Employee salary cannot be negative");
        }
    }

    ~Employee()
    {

    }
};

int main()
{
    Employee employee("Unknown", -1);
    return 0;
}