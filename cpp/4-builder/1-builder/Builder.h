
#ifndef _BUILDE_H_
#define _BUILDE_H_

#include "Product.h"

class Builder
{
public:
	virtual ~Builder() { cout<<"~Builder()"<<endl;};
	virtual void BuildPartA(const string& buildPara) = 0;
	virtual void BuildPartB(const string& buildPara) = 0;
	virtual void BuildPartC(const string& buildPara) = 0;


	// 此处是builder 中比较重要的方法  构建器必须实现的方法
	virtual Product* GetProduct() = 0;
protected:
	Builder()  { cout<<"Builder()"<<endl;};
private:
};

#endif // !1