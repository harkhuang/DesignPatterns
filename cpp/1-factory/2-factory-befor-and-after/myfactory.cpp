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

class Base
{
  public:
    Base(){};
    ~Base(){};
    virtual Base *makeProduct() = 0;
  private:
    vector <Product *> v_ps; // vps->write();  vps->read();
};



class ProductA: public Product{
    public: 
    
    Product * createProduct(){ return new ProductA();};
};

class ProductB: public Product{
    public: 
    Product * createProduct(){ return new ProductB();};
};


int
main()
{
    return 0;
}