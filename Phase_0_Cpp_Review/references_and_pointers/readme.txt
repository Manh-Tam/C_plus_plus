1. References
References in C++ are used to create an alias for a variable.
When the alias changes, the referencing varialbe also changes.
For example:
{
    int num = 3;
    int &ref = num;
    ref = 5; /* num becomes 5 also */
}
2. Pointers
Pointers in C++ are used to hold addresses of variables.
We can use pointers to change variable values.
For example:
{
    int num = 3;
    int *p = &num;
    *p = 5; /* num becomes 5 also */
}
3. Usage
an object is required. Use references for updating and printing
void update(int& x, int value)
{
    x = value;
}
void print(const &x)
{
    std::cout << x << std::endl;
}
No object is required. Use pointers for struct, class
struct linked_list
{
    int data;
    linked_list *p_tail;
};

class Student
{
private:
    string name;
    Teacher *teacher;
public:
};
