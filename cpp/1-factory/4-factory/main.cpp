#include "app.h"
#include "doc.h"

int main(int argc, char **argv)
{
    app *fac = new myApp();
    // 如何让我的工厂中含有更多的产品类型呢?  答案是不需要  不要把工厂模式和抽象工厂模式概念弄混
    //  仅仅是为了延迟构造 我们的对象(这个对象被改造  是个抽象基类的返回)
    Doc *p = fac->createDoc();



    
    app *fac1 = new myApp1();
    Doc *p1 = fac1->createDoc();


    return 0;
}