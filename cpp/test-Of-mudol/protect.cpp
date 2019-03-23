#include <iostream>
using namespace std;

class Base
{
protected:
    Base(void)    {        cout<< " Concrete Base"<<endl;    }
    ~Base(void)    {        cout<< " Destructor Base"<<endl;    }
protected:
    int m_a;
public: 
    void func () {cout << m_a << endl;}

    void func1 () {cout << private_int << endl;}

    private: int  private_int ;
};

class Sub:public Base
{
public:
    Sub(void)    {        cout<< " Concrete Sub"<<endl;    }
    virtual ~Sub(void)    {        cout<< " Destructor Sub"<<endl;    }
protected:
    void func () { m_a = 300; cout << private_int << endl;}
};

int main()
{
 //   Base a;

    getchar();
 }

 