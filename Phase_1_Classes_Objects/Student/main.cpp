#include <iostream>
#include <string>


class Student
{
private:
    std::string name;
    int age;
public:
    Student()
    {
        name = "Unknown";
        age = -1;
    }
    Student(std::string n, int a)
    : name(n), age(a){}

    void showInfo()
    {
        std::cout << "My name is " << name << " . I'm " << age << " years old." << std::endl;
    }
    void updateName(std::string name)
    {
        this->name = name;
    }
    void updateAge(int age)
    {
        this->age = age;
    }
    ~Student()
    {
        std::cout << "Student deleted\n";
    }
};

int main()
{
    Student student{"Nam", 20};
    student.showInfo();
    student.updateName("Tam");
    student.showInfo();
    student.updateAge(59);
    student.showInfo();
    return 0;
}