#include <iostream>
using namespace std;

// Single Inheritance example
class parent{
    public:
      int p_id;
};

// Derived/Inherited Class child is 'access_mode' public
class child: public parent{
    public:
      int c_id;
};

// Derived/Inherited Class child is 'access_mode' private
class child1: private parent{
    public:
      int c_id;
      void set_p_id(int i){
        p_id = i;
      }
      int print_p_id(){
          return p_id;
      }
};
/////////////////////////////////

// Multiple Inheritance example
class vehicle{
    public:
    vehicle(){
        cout<<"This is vehicle\n";
    }
};

class four_wheeler{
    public:
    four_wheeler(){
        cout<<"This is 4 wheeler\n";
    }
};

class car: public vehicle, public four_wheeler {
};
////////////////////////////////////////////

//Multi-level Inheritance example

//Base class1
class Vehicle{
    public:
    Vehicle(){
        cout<<"This is Vehicle\n";
    }
};

//Base class2
class FourWheeler: public Vehicle{
    public:
    FourWheeler(){
        cout<<"This is FourWheeler\n";
    }
};

//Derived class
class Car: public FourWheeler {
};

int main(){
    // Public class
    child c;
    c.c_id = 1;
    c.p_id = 2;
    cout<<c.c_id<<" "<<c.p_id<<'\n';

    // Private class
    child1 c1;
    c1.c_id = 1;
    c1.set_p_id(2);
    cout<<c1.c_id<<" "<<c1.print_p_id()<<'\n';

    //Multiple
    car car1;

    //Multi-level
    Car car2;
}