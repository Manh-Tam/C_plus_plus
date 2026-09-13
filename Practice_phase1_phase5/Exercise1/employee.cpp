#include "employee.hpp"

Employee::Employee()
{
    name = "Unknown";
    age = 18;
    salary = 0;
}
Employee::Employee(std::string name, int age, int salary)
{
    this->name = name;
    this->age = age;
    this->salary = salary;
}
std::string Employee::getName() const
{
    return this->name;
}
int Employee::getAge() const
{
    return this->age;
}
int Employee::getSalary() const
{
    return this->salary;
}
bool Employee::setName(const std::string& name)
{
    bool ret = false;
    if (name.length() > 0)
    {
        this->name = name;
        ret = true;
    }
    return ret;
}
bool Employee::setAge(const int& age)
{
    bool ret = false;
    if (age >= 18 && age <= 100)
    {
        this->age = age;
        ret = true;
    }
    return ret;
}
bool Employee::setSalary(const int& salary)
{
    bool ret = false;
    if (salary >= 0)
    {
        this->salary = salary;
        ret = true;
    }
    return ret;
}