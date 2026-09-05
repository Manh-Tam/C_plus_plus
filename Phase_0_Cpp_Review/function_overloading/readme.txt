Function overloading is a mechanism in C++ that allows multiple functions to have the same function name.
However, they must have at least one difference in their parameter list.
For example:
int add(int a, int b);
float add(float a, float b);
float add(int a, int b);