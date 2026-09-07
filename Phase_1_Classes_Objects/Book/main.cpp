#include <iostream>
#include <string>
class Book
{
private:
    std::string author;
    int price;
public:
    Book()
    {
        author = "Unknown";
        price = 0;
    }
    ~Book()
    {
        std::cout << "Book deleted\n";
    }
    void showInfo()
    {
        std::cout << "Author: " << author << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
    void setAuthor(std::string author)
    {
        this->author = author;
    }
    void setPrice(int price)
    {
        this->price = price;
    }
};

int main()
{
    Book book;
    book.showInfo();
    book.setAuthor("Jonathan");
    book.setPrice(100);
    book.showInfo();
    return 0;
}