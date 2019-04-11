
#include <string>  
#include <vector>  
#include <iostream>  

using namespace std;  



// ����
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


// ��һ���̳���   ְ�����չʾ�������
class SubMenu : public Menu    
{  
public:  
    SubMenu(){};  
    SubMenu(std::string strName): Menu(strName)  {};  
    virtual ~SubMenu() {};
    void Display() {      cout << m_strName << endl;  }  ;  
};  


//�ڶ����̳���  ��ϵ����   �ṩ��ͬ���͵��������ɾ�Ĳ�
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
    std::vector<Menu*> m_vMenu;    // ����һ����������� �ܹ��ں϶��
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
    //��չʾ���������˽ṹ
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
    Menu* pMenu = new CompositMenu("��������");      
    pMenu->Add(new SubMenu("ʱ������"));  
    pMenu->Add(new SubMenu("�������"));  
    Menu* yuleNode = new SubMenu("��������");
    yuleNode->Add(new SubMenu("���ж�"));
    pMenu->Add(yuleNode);  
    pMenu->Display();

    return 0;  
}  