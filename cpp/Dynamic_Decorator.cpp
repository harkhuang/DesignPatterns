#include <iostream>
#include <string>

struct Shape
{
  virtual std::string str() = 0;
};

struct Circle : Shape
{
  float radius = 10.0f;

  void resize(const float factor)
  {
    radius *= factor;
  }
  std::string str() override
  {
    return std::string("A circle of radius ") + std::to_string(radius);
  }
};

struct ColoredShape : Shape
{
  std::string color;
  Shape* shape{nullptr};

  ColoredShape(const std::string& clr, Shape* shp)
  {
    color = clr;
    shape = shp;
  }

  std::string str() override
  {
    return shape->str() + std::string(" which is coloured ") + color;
  }
};

// usage:
int main()
{
  Circle c;
  ColoredShape cc("red", &c);
  std::cout << cc.str() << std::endl;
  // cannot call this:
  cc.resize(1.2); // not part of ColoredShape

  return 0;
}
