#include <iostream>
#include <string>

struct Circle
{
    float radius = 10.0f;

    void resize(const float factor)
    {
        radius *= factor;
    }
    std::string str()
    {
        return std::string("A circle of radius ") + std::to_string(radius);
    }
};


// 优雅的实现修饰类   继承  灵活 牛逼
template <typename T> 
struct ColoredShape : T
{
    std::string color;

    ColoredShape(const std::string& clr)
    {
        color = clr;
    }
    std::string str()
    {
        return T::str() + " which is colored " + color;
    }
};

// usage:
int main()
{
    ColoredShape<Circle> red_circle("red");
    std::cout << red_circle.str() << std::endl;
    // and this is legal
    red_circle.resize(1.5f);
    std::cout << red_circle.str() << std::endl;
    return 0;
}