

#ifndef __DOC_H__
#define __DOC_H__



#include  <iostream>



// 这里 抽象模型类  可以是数据模型  也可以是业务模型
class Doc{
    public:
    Doc(){};
    Doc(char * path ){ memcpy(szPath, path, strlen(path));};
    virtual Doc *create(){ return this;};
    virtual void  open(){};
    virtual void  read(){};
    virtual void  wirte(){};
    virtual void  revert(){};
    
    // 重点  必须创建
    private:
    char  szPath[100];
};




class mydoc:public Doc{
    public: 
     // 不把这个写在这里的
     // doc抽象的是单纯的数据基类   
     // 单纯的继承关系  不做多的介绍
    //Doc * create(){ return new mydoc();}
    mydoc();
    ~mydoc();
};

class mydoc1:public Doc{
    public: 
     // 不把这个写在这里的
     // doc抽象的是单纯的数据基类   
     // 单纯的继承关系  不做多的介绍
    //Doc * create(){ return new mydoc();}
    mydoc1();
    ~mydoc1();
};


class yourdoc:public Doc{
    public: 
     // 不把这个写在这里的
     // doc抽象的是单纯的数据基类   
     // 单纯的继承关系  不做多的介绍
    //Doc * create(){ return new mydoc();}
    yourdoc();
    ~yourdoc();
};

#endif // __DOC_H__
