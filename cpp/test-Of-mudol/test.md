### 测试虚析构函数


Base *a = new Sub ; delete a;
 Concrete Base
 Concrete Sub
 Destructor Base
Base *b = new Sub ; delete b;
 Concrete Base
 Concrete Sub
 Destructor Sub
 Destructor Base
 [./VirtualDestructor.cpp]