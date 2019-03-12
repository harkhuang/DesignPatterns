#include "doc.h"
#include "app.h"

class source{
    public:
    Doc * getSrc(std::string path){
        return m_docs[path];
    }
    bool setSrc(std::pair<std::string, Doc*>){
        return true;
    }
    void addSrc(std::string path){
        std::pair<std::string, Doc*> member = make_pair(path , getSrc(path) );
        m_docs.insert(member);
    }
    private:
    std::map<std::string ,Doc *> m_docs;
};
