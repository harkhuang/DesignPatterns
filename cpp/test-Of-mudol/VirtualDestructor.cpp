#include <iostream>
using namespace std;

class Base
{
public:
    Base(void)    {        cout<< " Concrete Base"<<endl;    }
     ~Base(void)    {        cout<< " Destructor Base"<<endl;    }
};

class Sub:public Base
{
public:
    Sub(void)    {        cout<< " Concrete Sub"<<endl;    }
    ~Sub(void)    {        cout<< " Destructor Sub"<<endl;    }
};



class Base1
{
public:
    Base1(void)    {        cout<< " Concrete Base1"<<endl;    }
    // 使用多态 基类正确的打开方式
    virtual ~Base1(void)    {        cout<< " Destructor Base1"<<endl;    }
};

class Sub1:public Base1
{
public:
    Sub1(void)    {        cout<< " Concrete Sub1"<<endl;    }
    ~Sub1(void)    {        cout<< " Destructor Sub1"<<endl;    }
};

int main()
{
    // 基类Base中不存在子类的析构函数
    cout<<"Base *a = new Sub ; delete a;"<<endl;
    Base *a = new Sub ;
    delete a;
    // 子类包含基类,同样包括 析构函数
    cout<<"Sub *b = new Sub ; delete b;"<<endl;
    Sub *b = new Sub ;
    delete b;
    // 子类包含基类,同样包括 析构函数
    cout<<"Base *c = new VirtualSub ; delete c;"<<endl;
    Base1 *c = new Sub1 ;
    delete c;
    getchar();
 }

 