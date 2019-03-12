//
//  main.cpp
//  pattern design
//
//  Created by k on 2019/3/12.
//  Copyright © 2019年 黄奎. All rights reserved.
//

#include <iostream>
#include "app.h"
#include "doc.h"
int main() {
    
    app *fac = new myApp();
    // 如何让我的工厂中含有更多的产品类型呢?  答案是不需要  不要把工厂模式和抽象工厂模式概念弄混
    //  仅仅是为了延迟构造 我们的对象(这个对象被改造  是个抽象基类的返回)
    Doc *p = fac->createDoc();
    p->create();
    
    
    // step 1
    app *fac1 = new myApp1();
    // step 2
    Doc *p1 = fac1->createDoc();
    // step 3
    p1->create();
    
    return 0;
}
