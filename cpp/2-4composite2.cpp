
#include <string>  
#include <vector>  
#include <iostream>  

using namespace std;  



// 超类
class Menu    
{  
public:  
    virtual ~Menu()  {};  
    virtual void Add(Menu*) {};  
    virtual void Remove(Menu*) {};  
    virtual Menu* GetChild(int) {};   
    virtual void Display() = 0;  

protected:  
    Menu() {};
    Menu(std::string strName) : m_strName(strName) {  };
    std::string m_strName;  
};


// 第一个继承类   职责管理展示组合内容
class SubMenu : public Menu    
{  
public:  
    SubMenu(){};  
    SubMenu(std::string strName): Menu(strName)  {};  
    virtual ~SubMenu() {};
    void Display() {      cout << m_strName << endl;  }  ;  
};  


//第二个继承类  组合的组件   提供相同类型的组件的增删改查
class CompositMenu : public Menu  
{  
public:  
    CompositMenu();  
    CompositMenu(std::string strName)  : Menu(strName) {};  
    virtual ~CompositMenu()  {  }  ;  
  ///  void test(int xx)   : m_myint(xx) {};   //error
    void Add(Menu*);  
    void Remove(Menu*);  
    Menu* GetChild(int);  
    void Display();  
private:  
    std::vector<Menu*> m_vMenu;    // 这是一个超级组合类 能够融合多个
    int m_myint;
};  


void CompositMenu::Add(Menu* pMenu)  
{  
    m_vMenu.push_back(pMenu);  
}  

void CompositMenu::Remove(Menu* pMenu)  
{  
    vector<Menu *>::iterator it_back;
    for (vector<Menu *>::iterator it = m_vMenu.begin();it !=  m_vMenu.end();it++ )
    {
        if(pMenu == *it)
        {
            it = m_vMenu.erase( it );
            it--;           
        }
    }

}  

Menu* CompositMenu::GetChild(int index)  
{  
    return m_vMenu[index];  
}  

void CompositMenu::Display()  
{  
    //在展示层中体现了结构
    cout << "+" << m_strName << endl;  
    vector<Menu*>::iterator it = m_vMenu.begin();  
    for (; it != m_vMenu.end(); ++it)  
    {  
        cout << "|-";  
        (*it)->Display();  
    }  
}  


int main(int argc, char* argv[])  
{  
    Menu* pMenu = new CompositMenu("国内新闻");      
    pMenu->Add(new SubMenu("时事新闻"));  
    pMenu->Add(new SubMenu("社会新闻"));  
    Menu* yuleNode = new SubMenu("娱乐新闻");
    yuleNode->Add(new SubMenu("狗仔队"));
    pMenu->Add(yuleNode);  
    pMenu->Display();

    return 0;  
}  