#include <iostream>

class Product
{
public:
    virtual void askQuestions() = 0;
};

class ProductA : public Product
{
public:
    void askQuestions() override {
        std::cout << "Asking about design patterns!" << std::endl;
    }
};

class ProductB : public Product
{
public:
    void askQuestions() override {
        std::cout << "Asking about community building!" << std::endl;
    }
};

class Factory
{
public:
    void takeInterview() {
        Product* interviewer = this->ConcretePorduct();
        interviewer->askQuestions();
    }

protected:
// 表示 这个方法我要调用  但是我不实现  需要子类实现
// 抽象类中比较高级的写法
// protected 能修饰子类不可以访问
// =0 表示子类必须实现
// factory 表示各个抽象类之间的关系 列的产品
// factory 和  product 是依赖的关系
    virtual Product* ConcretePorduct() = 0;
};



// 抽象ProductType此处可以省略一万行代码
template <typename ProductType>
class ProductManager : public Factory {
protected:
    Product* ConcretePorduct() override {
        return new ProductType();
    }
};

int main()
{
// 工厂方法只有产品是抽象类  
// 区别抽象工厂  工厂也是抽象类
    Factory* devManager = new ProductManager<ProductA>();
    devManager->takeInterview();

    Factory* marketingManager = new ProductManager<ProductB>();
    marketingManager->takeInterview();

}
