#include <iostream>
#include <string>


// 此处为什么用结构体 表示 类?? 优点在哪里?
// struct   默认 public  
struct Shape
{
  virtual std::string str() = 0;  // 虚函数必须实现
};


 //继承了
struct Circle : Shape 
{
  // 用于修饰
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

// 继承类
struct ColoredShape : Shape
{
  std::string color;
  Shape* shape{nullptr};   // 被修饰后的类指针

  // 特有的
  ColoredShape(const std::string& clr, Shape* shp)
  {
    color = clr;
    shape = shp;
  }
  
  // 重写了
  std::string str() override   // c11 特性 重写
  {
    return shape->str() + std::string(" which is coloured ") + color;
  }
};

// usage:
// g++ -std=c++11
// 允许子类 组合类 灵活扩展和修改
int main()
{
  Circle c;   // 声明了 修饰类

  // 用子类修饰子类   等到新的子类属性
  // 封装原则  单一职责原则
  ColoredShape cc("red", &c);  
  // cc.resize(1.2); //  error  此处报错
  std::cout << cc.str() << std::endl;
  c.resize(1.2);
  std::cout << cc.str() << std::endl;
  
  // cannot call this:    --满足了封装和单一职责
  //cc.resize(1.2); // not part of ColoredShape  error
  // 但是我们可以用c.resize  重新修饰    子类Circle  职责是修改Circle属性  子类coler修饰colour属性
  
  return 0;
}


