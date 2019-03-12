
cmake -G "Xcode" .. 
生成了xcode 工程 




### 工厂模式


#### 思考








#### FAQ:
###### 为什么使用工厂模式?



##### 工厂模式中都有几个对象?

product   // 产品的基类  也就是抽象的数据模型 
producta productb  productc  等 // 产品派生出来的子类 可以有一万种

app(factory)         虚函数里面已经声明了
myapp(myfactory)    这里工厂只有一个吗













#### 工厂模式的别名
virtual constrct 
虚拟构造  延迟构造

####  在设计接口和框架的时候  我们的主要思想是什么?  分离?   组合? 