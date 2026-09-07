#include <iostream>

int main()
{
    int option = -1;
    int num1;
    int num2;
    while (1)
    {
        std::cout << "*** Simple calculator application ***" << std::endl;
        std::cout << "Please enter two numbers" << std::endl;
        std::cout << "Enter the first number: ";
        std::cin >> num1;
        std::cout << "Enter the second number: ";
        std::cin >> num2;
        std::cout << "Please choose one operation" << std::endl;
        std::cout << "1. Add" << std::endl;
        std::cout << "2. Subtract" << std::endl;
        std::cout << "3. Multiply" << std::endl;
        std::cout << "4. Divide" << std::endl;
        std::cout << "Your option: ";
        std::cin >> option;
        switch (option)
        {
        case 1:
            std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl; 
            break;
        case 2:
            std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
            break;
        case 3:
            std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
            break;
        case 4:
            std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
            break;
        default:
            break;
        }
        std::cout << std::endl;
    }
    return 0;
}