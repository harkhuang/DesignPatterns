#include <iostream>
#include <vector>
using namespace std;




// 产品不同的读写接口
class Product{
    public: 
    virtual void write(){};
    virtual void read(){};
    virtual Product * createProduct();
};

class ProductA: public Product{
    public: 
    
    Product * createProduct(){ return new ProductA();};
};

class ProductB: public Product{
    public: 
    Product * createProduct(){ return new ProductB();};
};


class IFactory
{
  public:
    IFactory(){};
    ~IFactory(){};
    virtual Product *makeProduct() = 0;
  private:
    vector <Product *> v_ps; // vps->write();  vps->read();
};

class Factory :public IProduct
{
    public:
    Product * createProductA(){ return new ProductA;}
    Product * createProductB(){ return new ProductB;}
}

int main()
{
    return 0;
}