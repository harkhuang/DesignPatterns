#ifndef _PRODUCTPART_H
#define _PRODUCTPART_H


#include <iostream>

using namespace std;
class ProductPart
{
public:
	ProductPart(){ cout<< "ProductPart "<<endl;};
	~ProductPart(){ cout<< "~ProductPart "<<endl;};
	ProductPart* BuildPart(){ return new ProductPart();}
protected:
private:
};

#endif