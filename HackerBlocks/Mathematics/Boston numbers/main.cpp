#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool composite(ll n){
    for(ll i=2;i<=sqrt(n);i++){
        if((n%i)==0)
           return true;
    }
    return false;
}

ll sum_calculator(ll m){
    ll sum =0;
    while(m){
        sum += m%10;
        m=m/10;
    }

    return sum;
}

int main() {
	ll n,m;
    cin>>m;
    n=m;
    if(!composite(n)){
        cout<<0;
        return 0;
    }

    ll primeFactorsSum =0;
    while(n%2==0){
        n/=2;
        primeFactorsSum +=2;
    }

    for(ll i=3;i<=sqrt(m);i+=2){
        while((n%i)==0){
            n/=i;
            primeFactorsSum +=sum_calculator(i);
        }
    }

    if(n>2)
        primeFactorsSum += sum_calculator(n);

     ll sum = sum_calculator(m);
    if(primeFactorsSum == sum){
        cout<<1;
    }
    else
        cout<<0;

    return 0;
}
