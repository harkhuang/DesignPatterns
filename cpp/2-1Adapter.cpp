#include <iostream>
using namespace std;

//适配接口
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
        std::cout<<"Target::Request()"<<std::endl;
    };
protected:
private:
};

//适配器方法
class Adaptee
{
public:
    Adaptee(){
        cout<<"Adaptee()"<<endl;
    };
    ~Adaptee(){
        cout<<"~Adaptee()"<<endl;
    };
    void SpecificRequest(){
        std::cout<<"Adaptee::SpecificRequest()"<<std::endl;
    };
protected:
private:
};

//适配器
class Adapter:public Target
{
public:
    Adapter(Adaptee* ade){
        // 在类中拷贝构造出来 旧接口对象
        std::cout<<"Adapter(Adaptee* ade)"<<std::endl;
        this->_ade = ade;
    };
    ~Adapter(){
         std::cout<<"~Adapter()"<<std::endl;
    };
    void Request(){
        _ade->SpecificRequest();
    }
;
protected:
private:
    Adaptee* _ade;
};




// 1）适配器：改变已有的两个接口，让他们相容。
// 2）桥接模式：分离抽象化和实现，使两者的接口可以不同，目的是分离。
int main(int argc,char* argv[])
{
    //用户根据类型名称自己适配
    Adaptee* ade = new Adaptee; // 构建出旧接口
    // 通过适配器  让旧接口适应新接口  得到我们的目标对象
    Target* adt = new Adapter(ade); 
    adt->Request();
    return 0;



    // 都是结构型       结构型    即    多重继承的组合
}