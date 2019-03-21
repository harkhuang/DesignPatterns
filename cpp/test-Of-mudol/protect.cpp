#include <iostream>
using namespace std;

class Base
{
public:
    Base(void)    {        cout<< " Concrete Base"<<endl;    }
    ~Base(void)    {        cout<< " Destructor Base"<<endl;    }
protected:
    int m_a;
public: 
    void func () {cout << m_a << endl;}
};

class Sub:public Base
{
public:
    Sub(void)    {        cout<< " Concrete Sub"<<endl;    }
    virtual ~Sub(void)    {        cout<< " Destructor Sub"<<endl;    }

    protected: 
    void func () { m_a = 300; cout << m_a << endl;}

};


int main()
{
    Base a;
    //a.m_a = 100;   // error 不可以访问 类外 保护成员
     a.func();

     Sub b;
     b.func();
    getchar();
 }

 