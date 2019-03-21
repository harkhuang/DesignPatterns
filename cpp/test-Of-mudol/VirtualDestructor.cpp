#include <iostream>
using namespace std;

class Base
{
public:
    Base(void)
    {
        cout<< " Concrete Base"<<endl;
    }
     ~Base(void)
    {
        cout<< " Destructor Base"<<endl;
    }

};

class Sub:public Base
{
public:

    Sub(void)
    {
        cout<< " Concrete Sub"<<endl;
    }

    ~Sub(void)
    {
        cout<< " Destructor Sub"<<endl;
    }

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

 