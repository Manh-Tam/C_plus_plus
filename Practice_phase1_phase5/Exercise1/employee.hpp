#pragma once

#include <iostream>

class Employee
{
private:
    std::string name;
    int age;
    int salary;
public:
    Employee();
    Employee(std::string name, int age, int salary);
    std::string getName() const;
    int getAge() const;
    int getSalary() const;
    bool setName(const std::string& name);
    bool setAge(const int& age);
    bool setSalary(const int& salary);
};