#include  <iostream>



// 这里 抽象模型类  可以是数据模型  也可以是业务模型
class Doc{
    public:
    virtual Doc *create() = 0;
    virtual void  open(){};
    virtual void  read(){};
    virtual void  wirte(){};
    virtual void  revert(){};
    
    // 重点  必须创建
    private:
    char * m_path;
};