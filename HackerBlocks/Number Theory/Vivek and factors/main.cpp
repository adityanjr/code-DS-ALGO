#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>sumOfFactors;

bool isPrime(ll n){
    if(n<=1)
        return false;
    if(n<=3)
        return true;

    if((n%2==0)||(n%3==0))
       return false;

    for(int i=5;i*i<=n;i+=6){
        if((n%i==0)||(n%(i+2)==0))
            return false;
    }
    return true;
}

void sum_of_factors(){
    sumOfFactors.push_back(INT_MIN);
    sumOfFactors.push_back(1);
    sumOfFactors.push_back(3);
    sumOfFactors.push_back(4);

    for(int i=4;i<=100000;i++){
        if(isPrime(i)){
            sumOfFactors.push_back(i+1);
            continue;
        }
        else{
            ll sum = 0;
            ll number  = i;
            for(int j=1;j<=sqrt(i);j++){
               if(number%j==0){
                 if(number/j==j)
                   sum+=j;
                else{
                    sum += number/j;
                    sum += j;
                 }
               }
            }
            sumOfFactors.push_back(sum);
        }
    }
}

ll findnumber(ll s){
    ll index = -1;
    for(ll i=0;i<sumOfFactors.size();i++){
        if(sumOfFactors[i]==s)
            index=i;
    }
    return index;
}

int main()
{
    ll s;
    sum_of_factors();
    while(true){
        cin>>s;
        if(s==0)
            break;
        ll ans = findnumber(s);
        if(ans==-1)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
