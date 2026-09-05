#include <iostream>
#include <string>
void update(int& num, int value)
{
    num = value;
}

struct teacher
{
    std::string name;
};

struct student
{
    std::string name;
    teacher *p_teacher;
};

int main()
{
    int a = 3;
    update(a, 5);
    std::cout << a << std::endl;

    student st;
    st.name = "Tom";
    st.p_teacher = nullptr;

    return 0;
}