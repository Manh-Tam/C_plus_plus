#include <iostream>
#include <vector>

class Product
{
private:
    std::string name;
    int price;
    int quantity;
public:
    Product(std::string name, int price, int quantity) 
    : name(name),
      price(price),
      quantity(quantity)
    {
        if (name.empty())
        {
            throw std::invalid_argument("Product name cannot be empty");
        }
        else if (price <= 0)
        {
            throw std::invalid_argument("Product price cannot be negative");
        }
        else if (quantity <= 0)
        {
            throw std::invalid_argument("Quantity cannot be negative");
        }
        else
        {

        }
    }
    std::string getName() const
    {
        return name;
    }
    void showInfor() const
    {
        std::cout << "Name: " << name << " Price: " << price << " Quantity: " << quantity << std::endl;
    }
};

class Inventory
{
private:
    std::vector<Product> products;
public:
    void addProduct(const Product& product)
    {
        products.push_back(product);
    }
    bool removeProduct(std::string product_name)
    {
        bool ret = true;
        if (product_name.empty())
        {
            ret = false;
        }
        else
        {
            int index = 0;
            for (auto product : products)
            {
                if (product_name == product.getName())
                {
                    break;
                }
                index++;
            }
            /*product name not found*/
            if (index == products.size())
            {
                ret = false;
            }
            else
            {
                products.erase(products.begin() + index);
            }
            
        }
        return ret;
    }
    const Product* findProduct(std::string product_name)
    {
        const Product *ptr = NULL;
        for (const auto& product : products)
        {
            if (product.getName() == product_name)
            {
                ptr = &product;
                break;
            }
        }
        return ptr;
    }
    void printInventory() const
    {
        for (const auto& product : products)
        {
            product.showInfor();
        }
    }
};

int main()
{
    Product product1("TV", 10, 100);
    Product product2("Laptop", 1, 1);
    Product product3("Mouse", 1, 1);
    Inventory inventory;
    inventory.addProduct(product1);
    inventory.addProduct(product2);
    inventory.addProduct(product3);
    std::cout << "Original inventory: \n";
    inventory.printInventory();

    std::string tobe_remove = "TV";
    inventory.removeProduct(tobe_remove);
    std::cout << "After removing TV:\n";
    inventory.printInventory();

    const Product *ptr = inventory.findProduct("Mouse");
    std::cout << "Finding mouse...\n";
    if (ptr != NULL)
    {
        std::cout << "Mouse found" << std::endl;
    }
    else
    {
        std::cout << "Mouse not found" << std::endl;
    }

    ptr = inventory.findProduct("TV");
    std::cout << "Finding TV...\n";
    if (ptr != NULL)
    {
        std::cout << "TV found" << std::endl;
    }
    else
    {
        std::cout << "TV not found" << std::endl;
    }
    return 0;
}