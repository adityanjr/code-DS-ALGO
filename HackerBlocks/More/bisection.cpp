#include<iostream>
#include<iomanip>
using namespace std;
int main(){
cout<<"Aditya Gupta"<<endl;
cout<<"Rollno-41820803117"<<endl;
cout<<"IT sem-4th"<<endl;
cout<<"Bisection method correct upto 3 decimal place:"<<endl;
float a,b,x;
int i=0,n;
cout<<"Enter a and b:"<<endl;
cin>>a>>b;
cout<<"Enter no.of iterations:\n";
cin>>n;
while(i<n){
    x=(a+b)/2;
    float ans=(x*x*x)-(2*x)-5;
    if(ans>0){
        b=x;
    }
    else{
        a=x;
    }
    i++;
}

cout<<"Root of the equation="<<setprecision(5)<<x;
return 0;
}

