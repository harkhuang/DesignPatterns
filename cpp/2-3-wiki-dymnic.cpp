#include <iostream>
#include <string>
/// 用struct 而不用class 的原因是 所有函数都使用 pubic 默认类型 而class 是private 类型
// 使得代码更加的简洁 
struct Circle  // 定义了形状类
{
    float radius = 10.0f;   // 形状的属性  也就是圆的半径

    void resize(const float factor)   // 设置半径的函数
    {
        radius *= factor;  // 允许成倍数的扩展
    }


    std::string str() // 输出圆的半径
    {
        return std::string("A circle of radius ") + std::to_string(radius);
    }

    //add  typename T test by huangkui 
    void mytest(){ std::cout<<"mytest"<std::endl;}
};


// 优雅的实现修饰类   继承  灵活 牛逼
// ColoredShape 继承了类型t 
//  动态继承类型  很他妈的牛逼  很他妈的灵活
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
    //  简单粗暴的代码  让我们对问题更加专注  
    // 1. 创建了修饰类Circle
    // 2. 用修饰类 修饰我们的主要类ColoredShape
    // 3. 灵活的模板使得我们的类可以成为任何一种类型的子类 牛逼牛逼  风骚风骚
    ColoredShape<Circle> red_circle("red");
    std::cout << red_circle.str() << std::endl;
    // and this is legal
    red_circle.resize(1.5f);
    std::cout << red_circle.str() << std::endl;
    return 0;
}