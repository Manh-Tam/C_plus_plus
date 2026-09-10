#include <iostream>

class Animal
{
protected:

public:
    Animal()
    {
        std::cout << "Animal created\n";
    }
    void Eat()
    {
        std::cout << "Eating ..." << std::endl;
    }
};

class Dog : public Animal
{

public:
    Dog()
    {
        std::cout << "Dog created" << std::endl;
    }
    void Eat()
    {
        std::cout << "Dog eating ..." << std::endl; 
    }
};

class Cat : public Animal
{
public:

};

class Bird : public Animal
{
public:

};

int main()
{
    // Animal animal;
    // animal.Eat();
    Dog dog;
    dog.Eat();

    Animal *animal = new Dog;
    animal->Eat();
    return 0;
}