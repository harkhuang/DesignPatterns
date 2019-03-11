
#ifndef  _APP_H_
#define  _APP_H_

#include <iostream>
#include <vector>
#include <map>
#include "doc.h"   // 这里将要对我们所构件对模型进行绑定

class app{
    public:
    virtual Doc * createDoc() = 0;
    protected:
    
    bool addDoc(std::string name);
    private:
    std::map<std::string ,Doc *> m_docs;
};

bool app::addDoc(std::string name){
    std::pair<std::string ,Doc *> member = make_pair(name, createDoc());
    m_docs.insert(member);
};

class myApp:public app{
public: 
    // 这里怎么调用 产品创建对引用呢  
    // 这里应该如何更好对衔接起来???
    
    Doc * createDoc();
    
};



class myApp1:public app{
public: 
    // 这里怎么调用 产品创建对引用呢  
    // 这里应该如何更好对衔接起来???
    Doc * createDoc();
    
};


#endif