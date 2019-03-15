#include "Builder.h"
#include <string>
using namespace std;
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
