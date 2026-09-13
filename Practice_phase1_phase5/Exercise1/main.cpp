#include <iostream>
#include "employee.hpp"

void printEmployee(const Employee& employee)
{
    std::cout << "Name:\t" << employee.getName() << std::endl;
    std::cout << "Age:\t" << employee.getAge() << std::endl;
    std::cout << "Salary:\t" << employee.getSalary() << std::endl;
}

int main()
{
    Employee employee("tam", 18, 10);
    printEmployee(employee);
    return 0;
}