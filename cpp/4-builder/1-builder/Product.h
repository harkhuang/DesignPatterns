#ifndef _PRODUCT_H
#define _PRODUCT_H
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

#endif