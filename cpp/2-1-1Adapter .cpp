#include <iostream>
using namespace std;


// 目标  我们最终需要调用接口的样子
class Target
{
public:
    Target(){
        cout<<"Target()"<<endl;
    };
    virtual ~Target(){
        cout<<"~Target()"<<endl;
    };
    virtual void Request(){
        cout<<"Target::Request"<<endl;
    };
protected:
private:
};


// 老接口 需要适配器
class Adaptee
{
public:
    Adaptee(){
        cout<<"Adaptee()" <<endl;
    };
    ~Adaptee(){
        cout<<"~Adaptee()" <<endl;
    };
    void SpecificRequest(){
         cout<<"Adaptee::SpecificRequest()" <<endl;
    }
    ;
protected:
private:
};

// 通过继承的方式绑定了适配器   (结构性)
// 定义一个已经存在的接口，这个接口需要适配。
class Adapter:public Target,private Adaptee
{
public:

    Adapter(){
        cout<<"Adapter() "<<endl;
    };
    ~Adapter(){
        cout<<"~Adapter() "<<endl;
    };
    void Request(){
        cout<<"Adapter::Request()"<<endl;
        // 适配器调整类型进行适配
        // TODO:可以根据生成类的参数或者属性构建不同的适配器
        // 举例子:1.识别类型,2.选择对应适配器
        this->SpecificRequest();
    };
protected:
private:
};

int main(int argc,char* argv[])
{
    //Adapter* adt = new Adapter();
    //创建类的同时,构建了适配器,这时候我们只关心使用的方法
    Target* adt = new Adapter();
    adt->Request();
    return 0;




    // 通过多重继承 使得子类中拥有两个类的方法,将两个类接洽起来  
    // 在子类中 自洽  两种父类的调用  这样 我们就可以通过
}