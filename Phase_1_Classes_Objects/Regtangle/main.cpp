#include <iostream>

class Regtangle
{
private:
    int width;
    int height;
public:
    Regtangle()
    {
        width = 0;
        height = 0;
    }
    Regtangle(int width, int height)
    {
        this->width = width;
        this->height = height;
    }
    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }
    void setWidth(int width)
    {
        if (width > 0)
        {
            this->width = width;
        }
    }
    void setHeight(int height)
    {
        if (height > 0)
        {
            this->height = height;
        }
    }
    int getArea()
    {
        return width * height;
    }
};

int main()
{
    Regtangle regtangle;
    std::cout << "Width: " << regtangle.getWidth() << " Height: " << regtangle.getHeight() << std::endl;
    regtangle.setWidth(3);
    regtangle.setHeight(5);
    std::cout << "Width: " << regtangle.getWidth() << " Height: " << regtangle.getHeight() << std::endl;
    std::cout << "Area: " << regtangle.getArea() << std::endl;
    return 0;
}