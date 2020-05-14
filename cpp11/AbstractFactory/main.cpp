#include <iostream>


// 门的抽象基类
class IDoor {
public:
    virtual void GetDescription() = 0;
};


//木门
class WoodenDoor : public IDoor {
public:
    void GetDescription() override {
        std::cout << "I am a wooden door" << std::endl;
    }
};
//铁门
class IronDoor : public IDoor {
public:
    void GetDescription() override {
        std::cout << "I am a iron door" << std::endl;
    }
};


//  安装门的工匠
class IDoorFittingExpert {
public:
    virtual void GetDescription() = 0;
};


// 木匠
class Carpenter : public IDoorFittingExpert {
    void GetDescription() override {
        std::cout << "I can only fit wooden doors" << std::endl;
    }
};


// 铁匠
class Welder : public IDoorFittingExpert {
    void GetDescription() override {
        std::cout << "I can only fit iron doors" << std::endl;
    }
};


<<<<<<< HEAD
// 抽象门工厂  (海尔工厂 )  可以安装热水器电热的  也可以安装气热的热水器
=======

// 超级抽象类=>包含了之前两个基类和超级基类(抽象工厂类)之间的关系 
// 工厂类中需要两个抽象基类  
// 用类模版传入类型 进行构造
>>>>>>> a3b075724238660d83cd45cdebe29d391f4e8bb9
class IDoorFactory {
public:
    virtual IDoor* MakeDoor() = 0;
    virtual IDoorFittingExpert* MakeFittingExpert() = 0;
};


// 模版用来传递对象类型 把抽象子类类型传递进来  真正的泛型编程
template <typename Door, typename DoorFittingExpert>
class DoorFactory : public IDoorFactory {
public:
    IDoor* MakeDoor() override {
        return new Door();
    }
    IDoorFittingExpert* MakeFittingExpert() override {
        return new DoorFittingExpert();
    }
};

int main()
{
    IDoorFactory* woodenFactory = new DoorFactory<WoodenDoor, Carpenter>();
    {
        IDoor* door = woodenFactory->MakeDoor();
        IDoorFittingExpert* expert = woodenFactory->MakeFittingExpert();
        door->GetDescription();
        expert->GetDescription();
    }

    IDoorFactory* ironFactory = new DoorFactory<IronDoor, Welder>();
    {
        IDoor* door = ironFactory->MakeDoor();
        IDoorFittingExpert* expert = ironFactory->MakeFittingExpert();
        door->GetDescription();
        expert->GetDescription();
    }
}
