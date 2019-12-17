#include <iostream>
using namespace std;
int x,y,GCD;

void extendedEuclid(int a, int b){
   if(b==0){
       x=1;
       y=0;
       GCD=a;
       return;
   }

  extendedEuclid(b,a%b);
  int Cx = y;
  int Cy = x - (a/b)*y;

  x = Cx;
  y = Cy;
}
int main() {
   int a,b;
   cin>>a>>b;

   // aX + bY = GCD(a,b)
   extendedEuclid(a,b);
   cout<<x<<" "<<y<<endl;
   cout<<GCD;

   return 0;
}
