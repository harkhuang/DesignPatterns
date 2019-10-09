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


// 抽象门工厂  (海尔工厂 )  可以安装热水器电热的  也可以安装气热的热水器
class IDoorFactory {
public:
    virtual IDoor* MakeDoor() = 0;
    virtual IDoorFittingExpert* MakeFittingExpert() = 0;
};

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
