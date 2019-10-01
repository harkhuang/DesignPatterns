#include <iostream>
using namespace std;





///  抽象的基类虽然多  
// 不要被吓到, 因为构建逻辑很简单 
// 产品 抽象 出N种
// 工厂 抽象 出N种
// 不同系列的产品 被不同的工厂使用 (比如我们把工厂产品按照高/中/底档去分配)


class AbstractProductA
{
public:
    virtual ~AbstractProductA();
protected:
    AbstractProductA();
private:
};
class AbstractProductB
{
public:
    virtual ~AbstractProductB();
protected:
    AbstractProductB();
private:
};
class ProductA1:public AbstractProductA
{
public:
    ProductA1();
    ~ProductA1();
protected:
private:
};
class ProductA2:public AbstractProductA
{
public:
    ProductA2();
    ~ProductA2();
protected:
private:
};
class ProductB1:public AbstractProductB
{
public:
    ProductB1();
    ~ProductB1();
protected:
private:
};
class ProductB2:public AbstractProductB
{
public:
    ProductB2();
    ~ProductB2();
protected:
private:
};
AbstractProductA::AbstractProductA()
{
}
AbstractProductA::~AbstractProductA()
{
}
AbstractProductB::AbstractProductB()
{
}
AbstractProductB::~AbstractProductB()
{
}
ProductA1::ProductA1()
{
    cout<<"ProductA1..."<<endl;
}
ProductA1::~ProductA1()
{
}
ProductA2::ProductA2()
{
    cout<<"ProductA2..."<<endl;
}
ProductA2::~ProductA2()
{
}
ProductB1::ProductB1()
{
    cout<<"ProductB1..."<<endl;
}
ProductB1::~ProductB1()
{
}
ProductB2::ProductB2()
{
    cout<<"ProductB2..."<<endl;
}
ProductB2::~ProductB2()
{
}


// 接口类构建技巧
// 1  使用多态，析构函数必须是虚函数 
// 2. 构造函数是保护成员，一个良好不可以被实例化的基类
// 3  必须实现的成员函数 定义 = 0 
class AbstractFactory
{
public:
    virtual ~AbstractFactory();


    ///******核心 多态*******///
    // 延迟了创建方法到子类中去 ， 将真正创建产品 延迟到client 端具体调用
    // 1.关联产品   2.子类实现构建具体产品（明确子类构建的具体产品      ）
    // 3.多个不同的产品构建出的索引   ，这也是反向的构建出了工厂
    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProductB* CreateProductB() = 0;
protected:
    AbstractFactory(); // 不允许直接构建这个基类 所以被定义为保护成员
private:
};
class ConcreteFactoryNick:public AbstractFactory
{
public:
    ConcreteFactoryNick();
    ~ConcreteFactoryNick();
    
    ///******实现核心*******///
    // 虚函数
    AbstractProductA* CreateProductA();
    AbstractProductB* CreateProductB();
protected:
private:
};
class ConcreteFactoryAdidas:public AbstractFactory
{
public:
    ConcreteFactoryAdidas();
    ~ConcreteFactoryAdidas();
    AbstractProductA* CreateProductA();
    AbstractProductB* CreateProductB();
protected:
private:
};

AbstractFactory::AbstractFactory()
{
}
AbstractFactory::~AbstractFactory()
{
}
ConcreteFactoryNick::ConcreteFactoryNick()
{
}
ConcreteFactoryNick::~ConcreteFactoryNick()
{
}
AbstractProductA* ConcreteFactoryNick::CreateProductA()
{
    return new ProductA1();
}
AbstractProductB* ConcreteFactoryNick::CreateProductB()
{
    return new ProductB1();
}
ConcreteFactoryAdidas::ConcreteFactoryAdidas()
{
}
ConcreteFactoryAdidas::~ConcreteFactoryAdidas()
{
}
AbstractProductA* ConcreteFactoryAdidas::CreateProductA()
{
    return new ProductA2();
}
AbstractProductB* ConcreteFactoryAdidas::CreateProductB()
{
    return new ProductB2();
}

int main(int argc,char* argv[])
{

    // 提供了更丰富自由的组合机制  
    // 不过这个实践起来 很难想象到适合这样复杂构建模式的场景
    AbstractFactory* cf1 = new ConcreteFactoryNick();
    cf1->CreateProductA();// 创建nike的鞋垫
    cf1->CreateProductB();// 创建nike的鞋盒
    AbstractFactory* cf2 = new ConcreteFactoryAdidas();
    cf2->CreateProductA();//创建阿迪的鞋带
    cf2->CreateProductB();//创建阿迪的鞋盒
    return 0;
}