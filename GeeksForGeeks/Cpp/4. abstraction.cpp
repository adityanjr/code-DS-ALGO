/*
Data abstraction is one of the most essential and important feature of object oriented programming in C++.
Abstraction means displaying only essential information and hiding the details. 
*/

#include <iostream>
using namespace std;

class A {
private:
  int x, y;
public:
  void set(int a, int b){
    x = a;
    y = b;
  }
  void display(){
    cout<<x<<" "<<y<<'\n';
  }
};

int main(){
  A a;
  a.set(1, 2);
  a.display();
}