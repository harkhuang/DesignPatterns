#include <iostream>
using namespace std;

//����ӿ�
class Target
{
public:
    Target(){
        cout<<"Target()"<<endl; 
    };
    virtual ~Target(){
        cout<<"~Target()"<<endl;
    };
    virtual void Request(){
        std::cout<<"Target::Request()"<<std::endl;
    };
protected:
private:
};

//����������
class Adaptee
{
public:
    Adaptee(){
        cout<<"Adaptee()"<<endl;
    };
    ~Adaptee(){
        cout<<"~Adaptee()"<<endl;
    };
    void SpecificRequest(){
        std::cout<<"Adaptee::SpecificRequest()"<<std::endl;
    };
protected:
private:
};

//������
class Adapter:public Target
{
public:
    Adapter(Adaptee* ade){
        // �����п���������� �ɽӿڶ���
        std::cout<<"Adapter(Adaptee* ade)"<<std::endl;
        this->_ade = ade;
    };
    ~Adapter(){
         std::cout<<"~Adapter()"<<std::endl;
    };
    void Request(){
        _ade->SpecificRequest();
    }
;
protected:
private:
    Adaptee* _ade;
};




// 1�����������ı����е������ӿڣ����������ݡ�
// 2���Ž�ģʽ��������󻯺�ʵ�֣�ʹ���ߵĽӿڿ��Բ�ͬ��Ŀ���Ƿ��롣
int main(int argc,char* argv[])
{
    //�û��������������Լ�����
    Adaptee* ade = new Adaptee; // �������ɽӿ�
    // ͨ��������  �þɽӿ���Ӧ�½ӿ�  �õ����ǵ�Ŀ�����
    Target* adt = new Adapter(ade); 
    adt->Request();
    return 0;



    // ���ǽṹ��       �ṹ��    ��    ���ؼ̳е����
}