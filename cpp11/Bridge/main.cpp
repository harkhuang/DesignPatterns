#include <iostream>
#include <string>

// 主题
class ITheme {
public:
    virtual std::string GetColor() = 0;
};


class DarkTheme : public ITheme {
public:
    std::string GetColor() override { return "Dark Black"; }
};

class LightTheme : public ITheme {
public:
    std::string GetColor() override { return "Off white"; }
};

class AquaTheme : public ITheme {
public:
    std::string GetColor() override { return "Light blue"; }
};




// 目的->使得每个web pag 都有一个主题 
// 实现方式->抽象页面基类  在构造过程中必须传入 抽象都主题
class IWebPage {
public:
// 抽象类构造需要参数  参数是另外一个抽象类
// 关联都关系  
// 使得抽象类  于 抽象类关联   
// 这里使用都是构造调用时候初始化.完成的
    IWebPage(ITheme& theme) : theme_(theme) {}
    virtual std::string GetContent() = 0;
protected:
    ITheme& theme_;
};

class About : public IWebPage {
public:

    // 继承方式在每次实现页面 过程中传递了主题参数
    About(ITheme& theme) : IWebPage(theme) {}
    std::string GetContent() override {
        return "About page in " + theme_.GetColor();
    }
};

class Careers : public IWebPage {
public:

    // 步骤 1. 继承抽象网页类
    // 步骤 2. 初始化构件抽象基类 传递网页主题参数

    // 初始化列表 构造抽象页面类必须传入 主题
    Careers(ITheme& theme) : IWebPage(theme) {}
    std::string GetContent() override {
        return "Careers page in " + theme_.GetColor();
    }
};

int main()
{
    DarkTheme darkTheme;
    LightTheme lightTheme;
    About about(lightTheme);
    Careers careers(darkTheme);
    std::cout << about.GetContent() << std::endl;
    std::cout << careers.GetContent() << std::endl;
}
