#include <iostream>

class Car
{
private:
    int price;
    std::string branch;
public:
    Car()
    {
        price = 0;
        branch = "Unknown";
    }
    Car(std::string branch, int price)
    {
        this->branch = branch;
        this->price = price;
    }
    ~Car()
    {
        std::cout << "Car deleted" << std::endl;
    }
    void setPrice(int price)
    {
        this->price = price;
    }
    void setBranch(std::string branch)
    {
        this->branch = branch;
    }
    int getPrice()
    {
        return price;
    }
    std::string getBranch()
    {
        return branch;
    }
    void showInfo()
    {
        std::cout << "Branch: " << branch << " \tPrice: " << price << std::endl;
    }
};


int main()
{
    Car car{"BMW", 1000};
    car.showInfo();
    return 0;
}