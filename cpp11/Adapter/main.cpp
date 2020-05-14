#include <iostream>



/// 抽象事件如下: 现在有一个狮子猎人 ,它只能捕获狮子,美洲狮,非洲狮等..
//              狮子就是原来的抽象基类   猎人类捕获抽象狮子类(狮子基类)
//          但是狮子猎人能捕获野狗吗?
//          答案是目前抽象类 并不适合 
//           需要对原来对道具做稍微对修改
//         具体实现如下 ->

// 狮子抽象类
class ILion {
public:
     // 咆哮
    virtual void Roar() {
        std::cout << "I am a Lion" << std::endl;
    }
};


// 猎人抽象类
class Hunter {
public:
    void Hunt(ILion& lion) {
        lion.Roar();
    }
};

// 野狗抽象类
class WildDog
{
public:
    // 犬吠
    void Bark() {
        std::cout << "I am a wild dog." << std::endl;
    }
};

//! now we added a new class `WildDog`, the hunter can hunt it also.
//! But we cannot do that directly because dog has a different interface.
//! To make it compatible for our hunter, we will have to create an adapter.
<<<<<<< HEAD
=======

// 现在我们添加一个新类野狗,这个猎人可以用它捕猎
// 但是我们不可以直接捕获野狗,因为野狗接口不同
// 使得野狗兼容猎人类

>>>>>>> a3b075724238660d83cd45cdebe29d391f4e8bb9
class WildDogAdapter : public ILion {
public:
    WildDogAdapter(WildDog& dog): dog_(dog) {}

// 继承狮子抽象类  然后重写


    // 这里的override 表示抽象子类重写基类的roar函数
    // 重写咆哮方法   犬吠 = 咆哮(这知识业务处理的最简单的一种模拟  ,当然  犬吠可以做加工让他更想咆哮)
    void Roar() override {
        // 野狗适配器  当然要让野狗咆哮了
        // 但是没有咆哮方法  
        // 那么只能犬吠了
        dog_.Bark();
    }
private:
    WildDog& dog_;
};


//适配器 实质就是调用其他类的  同样的方法 ,该方法具有相同的地方  ,但是并非抽象继承的关系 ,
// 我们只想做相应 的替换而已

int main()
{
    // 我是野狗
    WildDog dog; 
    // 野狗适配器
    WildDogAdapter dogAdapter(dog);
    // 猎人
    Hunter hunter;


    //!!!!!!这里传递对居然是  类  ??????
    //  确实不理解 怎么做到的呢?
    // 因为 dogAdapter 是抽象基类的继承子类   这样的写法虽然巧妙但是并没有那么容易理解.
    // 
    hunter.Hunt(dogAdapter);
}
