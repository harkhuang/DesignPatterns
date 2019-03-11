#include <iostream>
#include "doc.h"
#include "app.h"

class myApp:public app{
public: 
    bool addDoc(char *path){
        
    }

    // 这里怎么调用 产品创建对引用呢  
    // 这里应该如何更好对衔接起来???
    Doc * createDoc(){
        return  m;
    }

};