 #include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000000
ll a,b;
ll size1;

void sieve(ll p[]){
    memset(p,1,sizeof(p));
    p[0]=p[1]=0;
    for(ll i=2;i<=size1;i++){
        if(p[i]){
            for(ll j=2*i;j<=size1;j+=i){
                p[j]=0;
            }
        }
    }
}

void segemented_sieve(ll a, ll b){
    size1 = sqrt(b);
    ll p[size1+1];
    sieve(p);
    ll pp[b-a+1];
    memset(pp,1,sizeof(pp));
    for(ll i=2;i<=size1;i++){
         for(ll j=a;j<=b;j++){
             if(p[i]){
                 if(i==j)
                    continue;
                if(j%i==0)
                   pp[j-a]=0;
             }
         }
    }

    for(ll i=0;i<=b-a;i++){
        if(pp[i]){
            cout<<i+a<<" ";
        }
    }
}

int main(){
    cin>>a>>b;
    segemented_sieve(a,b);
    return 0;
}
