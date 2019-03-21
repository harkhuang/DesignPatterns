### 测试虚析构函数


为什么 不多态就不会有问题??

```

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

int main()
{
    cout<<"Base *a = new Sub ; delete a;"<<endl;
    Base *a = new Sub ; // 多态 动态绑定  但是不存在虚函数表 无法做动态绑定这件事情
    delete a;

    cout<<"Base *b = new Sub ; delete b;"<<endl;
    Sub *b = new Sub ; // 非多态 不许要动态绑定 子类中就包含基类的析构函数指针  那么析构过程会直接去调用基类析构方法 
    delete b;
    getchar();
 }

 
```



## 多态正确的打开方式
多态一定要将析构函数设置为虚函数
```
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
 
    // 子类包含基类,同样包括 析构函数
    cout<<"Base *c = new VirtualSub ; delete c;"<<endl;
    Base1 *c = new Sub1 ;
    delete c;




```


```多态有析构问题```
Base *a = new Sub ; delete a;
 Concrete Base
 Concrete Sub
 Destructor Base


```非多态无析构问题```
Base *b = new Sub ; delete b;
 Concrete Base
 Concrete Sub
 Destructor Sub
 Destructor Base
 [./VirtualDestructor.cpp]

