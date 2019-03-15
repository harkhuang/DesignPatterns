
#include "Builder.h"

using namespace std;

class ConcreteBuilder:public Builder
{
public:
	ConcreteBuilder(){
		cout<<"ConcreteBuilder"<<endl;
	}
	~ConcreteBuilder(){
		cout<<"~ConcreteBuilder"<<endl;
	}
	void BuildPartA(const string& buildPara){
	cout<<"Step1:Build PartA..."<<buildPara<<endl;	
	};
	void BuildPartB(const string& buildPara){
	cout<<"Step1:Build PartB..."<<buildPara<<endl;	
	};
	void BuildPartC(const string& buildPara){
		cout<<"Step1:Build PartC..."<<buildPara<<endl;	
	};
	Product* GetProduct(){
		BuildPartA("pre-defined");
		BuildPartB("pre-defined");
		BuildPartC("pre-defined");
		return new Product();
	}
protected:
private:
};
