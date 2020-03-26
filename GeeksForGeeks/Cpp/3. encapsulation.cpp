
/*
In normal terms Encapsulation is defined as wrapping up of data and information under a single unit.
In Object Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulates them.
Encapsulation also lead to data abstraction or hiding.
*/

#include <iostream>
using namespace std; 

class Encap {
private:
  int x;
public:
  void set(int a){
    x = a;
  }
  int get(){
    return x;
  }
};

int main(){
  Encap e;
  e.set(1);
  cout<<e.get();
}