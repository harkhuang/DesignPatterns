#include <iostream>
#include <vector>

#include "doc.h"   // 这里将要对我们所构件对模型进行绑定
class app{
    public:
    virtual Doc * createDoc() = 0;
    private:
    std::vector<Doc *> m_docs;
};