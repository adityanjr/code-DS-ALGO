 #include<iostream>
using namespace std;
#define ll long long
ll factorial(ll n,ll k){
     if(k>n-k)
        k=n-k;
     ll result =1;
     for(int i=0;i<k;i++){
        result = result*(n-i)/(i+1);
     }
     return result;
}
int main() {
   int t;
   ll k,n;
   cin>>t;
   for(int i=0;i<t;i++){
       cin>>n>>k;
       ll result = factorial(n-1,k-1);
       cout<<result<<endl;
   }
}
