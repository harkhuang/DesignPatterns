class ICar {
public:
  virtual void DriveCar() = 0;
};

class Car : public ICar {
  void DriveCar() override {
    std::cout << "Car has been driven!" << std::endl;
  }
};

class ProxyCar : public ICar {
private:
  ICar* realCar;
  int _driver_age;

public:
  ProxyCar (int driver_age) : realCar(new Car()), _driver_age(driver_age) {}
  ~ProxyCar () {
    delete realCar;
  }

  void DriveCar() {
    if (_driver_age > 16)
      realCar->DriveCar();
    else
      std::cout << "Sorry, the driver is too young to drive." << std::endl;
  }
};

// How to use above Proxy class?
int main()
{
    ICar* car = new ProxyCar(16);
    car->DriveCar();
    delete car;

    car = new ProxyCar(25);
    car->DriveCar();
    delete car;
}
