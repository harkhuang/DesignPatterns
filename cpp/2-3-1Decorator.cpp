#include <iostream>
#include <string>
using namespace std;

// 抽象组件 (饮料)
class Beverage
{
public:
    Beverage()
    {
        m_description = string("Unknown Beverage");
        cout << "Beverage()" << endl;
    }

    virtual string getDescription()
    {
        cout << "Beverage::getDescription()" << endl;
        return m_description;
    }

    virtual double cost() = 0;

public:
    string m_description;
};

//////同级别修饰者
// 抽象装饰者
class CondimentDecorator : public Beverage
{
public:
    virtual string getDescription() = 0;
};

// 具体组件：Espresso (浓咖啡)
class Espresso : public Beverage
{
public:
    Espresso()
    {
        m_description = string("Espresso");
        cout << "Espresso()" << endl;
    }

    virtual double cost()
    {
        return 1.99;
    }
};

// 具体组件：HouseBlend
class HouseBlend : public Beverage
{
public:
    HouseBlend()
    {
        m_description = string("HouseBlend");
    }

    virtual double cost()
    {
        return 0.89;
    }
};

// 具体组件：DarkRoast
class DarkRoast : public Beverage
{
public:
    DarkRoast()
    {
        m_description = string("DarkRoast");
    }

    virtual double cost()
    {
        return 1.01;
    }
};

// 具体组件：Decaf
class Decaf : public Beverage
{
public:
    Decaf()
    {
        m_description = string("Decaf");
    }

    virtual double cost()
    {
        return 0.57;
    }
};

//////同级别修饰者


// 具体装饰者：Mocha  (可有可无的修饰物)
class Mocha : public CondimentDecorator
{
public:
    Mocha(Beverage *p_beverage)
    {
        m_beverage = p_beverage;
        cout << "Mocha()" << endl;
    }

    virtual string getDescription()
    {
        return m_beverage->getDescription() + ", Mocha";
    }

    virtual double cost()
    {
        return 0.20 + m_beverage->cost();
    }
private:
    Beverage *m_beverage;
};

// 具体装饰者：Milk (可有可无的修饰物)  会影响产品属性 改变产品具体成员
class Milk : public CondimentDecorator
{
public:
    Milk(Beverage *p_beverage)
    {
        m_beverage = p_beverage;
        cout << "Milk()" << endl;
    }

    virtual string getDescription()
    {
        return m_beverage->getDescription() + ", Milk";
    }

    virtual double cost()
    {
        return 0.50 + m_beverage->cost();
    }
private:
    Beverage *m_beverage;
};

// 具体装饰者：Soy (可有可无的修饰物)
class Soy : public CondimentDecorator
{
public:
    Soy(Beverage *p_beverage)
    {
        m_beverage = p_beverage;
        cout << "Soy()" << endl;
    }

    virtual string getDescription()
    {
        return m_beverage->getDescription() + ", Soy";
    }

    virtual double cost()
    {
        return 0.15 + m_beverage->cost();
    }
private:
    Beverage *m_beverage;
};

// 具体装饰者：Whip
class Whip : public CondimentDecorator
{
public:
    Whip(Beverage *p_beverage)
    {
        m_beverage = p_beverage;
        cout << "Whip()" << endl;
    }

    virtual string getDescription()
    {
        return m_beverage->getDescription() + ", Whip";
    }

    virtual double cost()
    {
        return 0.15 + m_beverage->cost();
    }
private:
    Beverage *m_beverage;
};

int main(void)
{

    // 饮料主类
    Beverage *p_beverage = new Espresso;
    // 装饰用 穆哈咖啡类型饮料 并且改变相应的价格
    p_beverage = new Mocha(p_beverage);
    // 装饰用 饮料中加入牛奶  并且改变相应的价格
    p_beverage = new Milk(p_beverage);
    // 装饰用 饮料中加入酱油 并且改变相应的价格
    p_beverage = new Soy(p_beverage); 
    // 装饰用 搅拌饮料  并且改变价格
    p_beverage = new Whip(p_beverage);

    // 获取被修饰后的
    p_beverage->getDescription();
    p_beverage->cost() ;
    cout << p_beverage->getDescription() << " " << p_beverage->cost() << endl;
    return 0;
}
