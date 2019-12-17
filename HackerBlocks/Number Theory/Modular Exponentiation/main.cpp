#include<iostream>
using namespace std;
#define ll long long int
ll modularexponentiation(ll a, ll b, ll c){
    ll res = 1;
    a = a % c;

    while(b>0){
        if(b&1)
           res = (res*a) % c;

        b =b>>1;
        a = (a*a)%c;

    }
  return res%c;

}
int main() {

    ll a,b,c;

    cin>>a>>b>>c;
    cout<<modularexponentiation(a,b,c);
	return 0;
}
