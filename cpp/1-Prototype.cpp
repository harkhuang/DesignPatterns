#include <iostream>
using namespace std;

class Prototype
{
public:
    virtual ~Prototype(){ itmep_ = 100;};
    virtual Prototype* Clone() const = 0;
protected:
    Prototype(){};
private:
    int itmep_ ;

};


class ConcretePrototype:public Prototype
{

public:
    ConcretePrototype() {  };
    ~ConcretePrototype() {};

    ///**********核心关键************///
    ConcretePrototype(const ConcretePrototype& cp);

    // 不允许对成员修改
    Prototype* Clone() const;

protected:
private:

int subi_;

};



Prototype* Prototype::Clone() const
{

    return 0;
}

ConcretePrototype::ConcretePrototype(const ConcretePrototype& cp)
{


    cout<<"ConcretePrototype copy ..."<<endl;
}



// 不允许修改成员对象

// cosnt 在后面不允许修改成员变量
// const 在前表示不允许修改返回值
// const 在变量前面表示不允许修改变量
// const 在指针前面表示不允许修改指针
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