#include <iostream>

using namespace std;



class Singleton
{
public:
	static Singleton* GetInstance();
protected:
		 Singleton();  // 不允许客户端直接实例化的类
private:
	static Singleton* _instance;  // 不允许继承类调用的
};


Singleton::Singleton()
{
	cout<<"Construct Singleton...."<<endl;
}
Singleton* Singleton::GetInstance()
{
	if (_instance == 0)
	{
		_instance = new Singleton();
	}
	return _instance;
}
Singleton* Singleton::_instance = 0;



int main(int argc,char* argv[])
{
	Singleton* sgn = Singleton::GetInstance();

	//Singleton* sgn11 = Singleton::GetInstance();
	return 0;
}