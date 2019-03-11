#include "doc.h"


class mydoc:public Doc{
    public:
    
    // 延迟加载起到一定作用
    void open(){

    }
    void read(){

    };
    void write(){

    };
     

     // 不把这个写在这里的
     // doc抽象的是单纯的数据基类   
     // 单纯的继承关系  不做多的介绍
    //Doc * create(){ return new mydoc();}
    private:
    mydoc(){};
    ~mydoc(){};
   
};