class Prototype
{
public:
    virtual ~Prototype();
    virtual Prototype* Clone() const = 0;
protected:
    Prototype();
private:
};


class ConcretePrototype:public Prototype
{

public:
    ConcretePrototype();
    ~ConcretePrototype();

    ///**********核心关键************///
    ConcretePrototype(const ConcretePrototype& cp);
    Prototype* Clone() const;
protected:
private:
};

#include <iostream>
using namespace std;
Prototype::Prototype()
{
}
Prototype::~Prototype()
{
}
Prototype* Prototype::Clone() const
{
    return 0;
}
ConcretePrototype::ConcretePrototype()
{
}
ConcretePrototype::~ConcretePrototype()
{

}
ConcretePrototype::ConcretePrototype(const ConcretePrototype& cp)
{
    cout<<"ConcretePrototype copy ..."<<endl;
}
Prototype* ConcretePrototype::Clone() const
{
    // 完成一次拷贝构造 并不是
    return new ConcretePrototype(*this);
}

#include <iostream>
using namespace std;
int main(int argc,char* argv[])
{
    Prototype* p = new ConcretePrototype();
    Prototype* p1 = p->Clone();

    cout<<p<<"\n" <<p1<<endl;
    return 0;
}