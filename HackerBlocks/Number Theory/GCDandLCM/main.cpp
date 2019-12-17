#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b==0)
      return a;
    else
      return gcd(b,a%b);
}
int main(){
    int a,b;
    cin>>a>>b;
    int GCD = gcd(a,b);
    cout<<"GCD: "<<GCD<<endl;
    int lcm = (a*b)/GCD;
    cout<<"LCM: "<<lcm<<endl;
    return 0;
}
