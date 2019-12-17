#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll primefactors(ll n){
     ll even_sum =0;
     ll odd_sum=0;
     ll number = n;
    for(ll i=1;i<=sqrt(n);i++){
        if(number%i==0){
            if(number/i==i){
                if(i&1)
                  odd_sum +=i;
                else
                   even_sum += i;
            }
            else {
            ll a = number/i;
            if(i&1)
                 odd_sum +=i;
            else
                even_sum +=i;
            if(a&1)
                odd_sum += a;
            else
                even_sum+=a;
            }
        }
    }
    cout<<even_sum<<endl;
    cout<<odd_sum<<endl;
    return even_sum-odd_sum;
}
int main()
{
    ll q,n;
    cin>>q;
    while(q--){
        n=0;
        cin>>n;
        cout<<primefactors(n)<<endl;
    }
    return 0;
}
