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
    
    Doc * create(){ return new mydoc();}
    private:
    mydoc(){};
    ~mydoc(){};
   
};