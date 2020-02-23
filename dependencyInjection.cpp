// https://www.codymorterud.com/design/2018/09/07/dependency-injection-cpp.html

#include <iostream>

using namespace std;

class GasSource {

public:
  virtual void FuelUp() = 0;
  virtual ~GasSource() = default;
};

class GasStation : public GasSource {

public:
  virtual void FuelUp() {
    cout << "Fueling up at the Gas station!" << endl;
  }
};

class FuelCan : public GasSource {

public:
  virtual void FuelUp () {
    cout << "Filling out with a fuel can!" << endl;
  }
};

class Car {
  GasSource *gasSource = NULL;

public:
  Car(GasSource *_gasSource) {
    this->gasSource = _gasSource;

    if (gasSource == NULL) {
      cout << "Gas source is not initlaized!" << endl;
    }
  }

  void fuelUpTheCar () {
    gasSource->FuelUp();
  }
};

int main () {

  GasSource* gasSource = new GasStation();
  GasSource* _gasSource = new FuelCan();

  Car *car1 = new Car(gasSource);
  car1->fuelUpTheCar();

  Car *car2 = new Car(_gasSource);
  car2->fuelUpTheCar();

  return 0;
}
