#include <iostream>
#include <string>
class Car {
  public:
    std::string color;
    int speed;

    void accelerate(int increase) {
      speed += increase;
      std::cout << "The" << color << "car is now at a speed of" << speed << "km/h." << std::endl;
    }
};

int main() {
  //Create an object of the Car class
  Car myCar;

  // Access and set member variables
  myCar.color = "Red";
  myCar.speed = 0;

  std::cout << "My car is a" << myCar.color << "car, starting at" << myCar.speed << "km/h." << std::endl;

  //Call the member function
  myCar.accelerate(50);
  myCar.accelerate(20);

  std::cout << std::endl;

  //Create another object
  Car anotherCar;
  anotherCar.color = "Blue";
  anotherCar.speed = 0;

  std::cout << "My friend's car is a" << anotherCar.color << "car, starting at" << anotherCar.speed << "km/h." << 
  std::endl;
  anotherCar.accelerate(30);

  return 0;
}