/*
The singleton pattern is a design pattern that restricts the instantiation of a class to one object.
*/

#include <iostream>
using namespace std;

// Classic Implementation
class Singleton {
private:
  static Singleton *s;
  Singleton() {
    cout<<"call";
  };
public:
  static Singleton* get_instance(){
    if(Singleton::s)
      return Singleton::s;
    s = new Singleton();
    return s;
  }
};

Singleton* Singleton::s = NULL;

int main(){
  Singleton *s1, *s2;
  s1 = Singleton::get_instance();
  s2 = Singleton::get_instance();
}
