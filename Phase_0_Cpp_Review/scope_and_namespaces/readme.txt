1. Scope
Global variables can be used everywhere inside a file.
Local variables can be used within a function.

Shadowing
int age = 30;
int main()
{
    int age = 20;
    std:: cout << age; //local var
    std::cout << ::age; //global var
}

2. Namespace
Namespace answers
"Which group does this name belong to?"

namespace dog{
    void speak()
    {
        std::cout << "Gau Gau" << std::endl;
    }
}

namespace cat{
    void speak()
    {
        std::cout << "Meo Meo" << std::endl;
    }
}

when call
dog::speak(); // => call speak function of dog
cat::speak(); // => call speak function of cat