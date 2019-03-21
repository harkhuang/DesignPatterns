### 测试虚析构函数


为什么 不多态就不会有问题??

非多态构成的函数不会被

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
    Base *a = new Sub ;
    delete a;

    cout<<"Base *b = new Sub ; delete b;"<<endl;
    Sub *b = new Sub ;
    delete b;
    getchar();
 }

 
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

