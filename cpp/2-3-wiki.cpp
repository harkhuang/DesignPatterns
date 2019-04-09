#include <iostream>
#include <string>


// 此处为什么用结构体 表示 类?? 优点在哪里?
// struct   默认 public  
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
// g++ -std=c++11
// 允许子类 组合类 灵活扩展和修改



int main()
{
  Circle c;

  
  ColoredShape cc("red", &c);
  // cc.resize(1.2); //  error  此处报错
  std::cout << cc.str() << std::endl;
  c.resize(1.2);
  std::cout << cc.str() << std::endl;
  // cannot call this:
  //cc.resize(1.2); // not part of ColoredShape  error
  return 0;
}


