#include <iostream>
#include <string>
using namespace std;


#include "ProductPart.h"
#include "ConcreteBuilder.h"
#include "Director.h" 
#include "Builder.h"

int main(int argc,char* argv[])
{

	// 在用户层创建builder 构造器  
	Builder* b = new ConcreteBuilder();
	Director* d = new Director(b);
	// 在用户层暴露出 builder parts 
	// 可以在director 中构件出更多的模型


	// 通过d构件复杂对象
	d->Construct("a+","b+","a-");



	// 表示对象 使用builder 表示复杂对象
	b->GetProduct();
	return 0;
}