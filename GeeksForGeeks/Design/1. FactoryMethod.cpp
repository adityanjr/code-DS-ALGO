// Factory Method - Design pattern

#include <iostream>
using namespace std;

//Library Class
class Vehicle {
public:
  virtual void printVehicle() = 0;
};
class TwoWheeler: public Vehicle {
public:
  void printVehicle() {
    cout<<"This is TwoWheeler\n";
  }
};
class FourWheeler: public Vehicle {
public:
  void printVehicle(){
    cout<<"This is FourWheeler\n";
  }
};

//Client (or User) Class
class Client {
private:
  Vehicle *pVehicle;

public:
  Client(int type){
    if (type == 1){
      pVehicle = new TwoWheeler();
    }
    else if (type == 2){
      pVehicle = new FourWheeler();
    }
    else {
      pVehicle = NULL;
    }
  }

  ~Client() {
    if (pVehicle){
      //delete pVehicle;
      pVehicle = NULL;
    }
  }

  Vehicle *getVehicle(){
    return pVehicle;
  }
};

int main(){
  Client *pClient = new Client(1);
  Vehicle *pVehicle = pClient->getVehicle();
  pVehicle->printVehicle();
}