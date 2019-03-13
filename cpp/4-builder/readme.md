#### BUILDER(生成器)— 对象创建型模式

1. **意图** 将一个**复杂对象**的构件(对象)与它的表示(对象)分离,是的同样的构件过程可以创建不同的表示(对象).
            Builder设计模式是二十三种着名的GoF设计模式之一[1]，描述了如何解决面向对象软件中的重复设计问题。
            Builder设计模式解决了以下问题：
            类（相同的构造过程）如何创建复杂对象的不同表示？
            如何简化包含创建复杂对象的类？
            直接在类中创建和组装复杂对象的各个部分是不灵活的。它提交类来创建复杂对象的特定表示，并且使得以后无法独立于（无需更改）类来更改表示。
            Builder设计模式描述了如何解决此类问题：
            封装在单独的Builder对象中创建和组装复杂对象的各个部分 。
            类将对象创建委托给Builder对象，而不是直接创建对象。
            类（相同的构造过程）可以委托给不同的Builder对象来创建复杂对象的不同表示。
2. **动机**  
   复杂对象的拆分  ,   构件过程抽象拆分   ,   组成部分抽象拆分(如果是单纯的组合可能就和工厂更加类似了)
   复杂的富文本编辑器   包含窗口(各种样式)     包含字体(各种样式)   包含字符集(各种样式)
   构建出一个文本编辑器   (例如:需要 qt风格窗口  + 微软的字体  + utf-8的字符集) 传递参数去

   让我们创建复杂对象变得更加的简单
   
   在使用设计模式之前我们应该在有类图  构件大致的关系

    **优点**
    Builder模式的优点包括： 

    允许您更改产品的内部表示。
    封装用于构造和表示的代码。
    提供对施工过程步骤的控制。
    **缺点**
    Builder模式的缺点包括： 

    需要为每种不同类型的产品创建单独的ConcreteBuilder。
    要求构建器类是可变的。
    不保证类的数据成员被初始化。
    可能不太支持依赖注入。
    
3. **适用性**
4. **结构**
5. **参与者**
6. **写作**
7. **效果**
8. **实现**
9.  **代码示例**
    ```
    class Car is
    Can have GPS, trip computer and various numbers of seats.
    Can be a city car, a sports car, or a cabriolet.

    class CarBuilder is
    method getResult() is
        output:  a Car with the right options
        Construct and return the car.

    method setSeats(number) is
        input:  the number of seats the car may have.
        Tell the builder the number of seats.

    method setCityCar() is
        Make the builder remember that the car is a city car.

    method setCabriolet() is
        Make the builder remember that the car is a cabriolet.

    method setSportsCar() is
        Make the builder remember that the car is a sports car.

    method setTripComputer() is
        Make the builder remember that the car has a trip computer.

    method unsetTripComputer() is
        Make the builder remember that the car does not have a trip computer.

    method setGPS() is
        Make the builder remember that the car has a global positioning system.

    method unsetGPS() is
        Make the builder remember that the car does not have a global positioning system.

    Construct a CarBuilder called carBuilder
    carBuilder.setSeats(2)
    carBuilder.setSportsCar()
    carBuilder.setTripComputer()
    carBuilder.unsetGPS()
    car := carBuilder.getResult()
    ```
10. **已知应用**
11. **相关模式**