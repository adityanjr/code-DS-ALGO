#include <iostream>
using namespace std;

//1. Compile time polymorphirsm - function overloading, operator overloading

//1.1 Function overloading
class Add{
    public:
        int func(int x, int y){
            return x+y;
        }
        double func(double x, double y){
            return x+y;
        }
};

//1.2 Operator overloading
class Complex{
    int r, i;
public:
    Complex(int a=0, int b=0){
        r=a; i=b;
    }
    Complex operator + (Complex const &obj){
        Complex res;
        res.r = r + obj.r;
        res.i = i + obj.i;
        return res;
    }
    void print(){
        cout<<r<<" i"<<i<<'\n';
    }
};

//2. Runtime polymorphism

//2.1 Function overriding
class Parent{
public:
    void print(){
        cout<<"Parent function\n";
    }
};

class Child: public Parent{
public:
    // Function overriden 
    void print(){
        cout<<"Child function\n";
    }
};

int main(){
    Add a;
    cout<<a.func(1, 1)<<" "<<a.func(1.1, 1.1)<<'\n';

    Complex c(1, 1);
    Complex c1(2, 2);
    Complex c2 = c+c1;
    c2.print();

    Parent pa;
    Child ch;
    pa.print();
    ch.print();
}