
#ifndef  _APP_H_
#define  _APP_H_

#include <iostream>
#include <vector>
#include <map>
#include "doc.h"   // 这里将要对我们所构件对模型进行绑定

class app{
    public:
    virtual Doc * createDoc() = 0;
    //void addDoc(std::string name);

};



class myApp:public app{
public: 
    // 这里怎么调用 产品创建对引用呢  
    // 这里应该如何更好对衔接起来???
    // 使用聚合方式把相关的类型引入到接口中来
    Doc * createDoc();
    
};



class myApp1:public app{
public: 
    // 这里怎么调用 产品创建对引用呢  
    // 这里应该如何更好对衔接起来???
    Doc * createDoc();
    
};

class yourApp:public app{
    public: 
    Doc * createDoc();
};

#endif
