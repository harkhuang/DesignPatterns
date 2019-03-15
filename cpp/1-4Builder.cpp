#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
	Product() {cout<< "Product "<<endl;};
	~Product(){cout<< "~Product "<<endl;};
protected:
private:
};

class ProductPart
{
public:
	ProductPart(){ cout<< "ProductPart "<<endl;};
	~ProductPart(){ cout<< "~ProductPart "<<endl;};
	ProductPart* BuildPart(){ return new ProductPart();}
protected:
private:
};
class Builder
{
public:
	virtual ~Builder() { cout<<"~Builder()"<<endl;};
	virtual void BuildPartA(const string& buildPara) = 0;
	virtual void BuildPartB(const string& buildPara) = 0;
	virtual void BuildPartC(const string& buildPara) = 0;

	// 重要
	virtual Product* GetProduct() = 0;
protected:
	Builder()  { cout<<"Builder()"<<endl;};
private:
};

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

class Director
{
public:
	Director(Builder* bld){
		_bld = bld;
	}
	~Director();

	// 此处构造 是作为一个整体
	void Construct(const string a,const string b,const string c){
		_bld->BuildPartA(a);
		_bld->BuildPartB(b);
		_bld->BuildPartC(c);
	}
	void Construct1(const string part_a_param,const string part_b_param,const string part_c_param){
		_bld->BuildPartA(part_a_param);
		_bld->BuildPartB(part_b_param);
		_bld->BuildPartC(part_c_param);
	}
protected:
private:
	Builder* _bld;
};

int main(int argc,char* argv[])
{

	// 在用户层创建builder 构造器  
	Director* d = new Director(new ConcreteBuilder());
	// 在用户层暴露出 builder parts 
	// 可以在director 中构件出更多的模型
	d->Construct("a+","b+","a-");
	return 0;
}