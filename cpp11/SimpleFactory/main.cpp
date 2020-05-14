#include <iostream>

class IDoor {
public:
    virtual float GetWidth() = 0;
    virtual float GetHeight() = 0;
};

class WoodenDoor : public IDoor {
public:
    WoodenDoor(float width, float height): m_width(width), m_height(height){}
    float GetWidth() override { return m_width; }
    float GetHeight() override { return m_height; }

protected:
    float m_width;
    float m_height;
};

class DoorFactory {
public:
    static IDoor* MakeDoor(float width, float heigh)
    {
        // 简单工厂 不具备通用型
        // 每次添加新产品  需要在工厂类中添加相应的子类方法
        return new WoodenDoor(width, heigh);
    }
};

int main()
{
    IDoor* door = DoorFactory::MakeDoor(100, 200);
    std::cout << "Width: " << door->GetWidth() << std::endl;
    std::cout << "Height: " << door->GetHeight() << std::endl;
}
