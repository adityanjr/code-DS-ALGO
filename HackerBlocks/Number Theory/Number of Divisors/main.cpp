#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<int>vec(1000001);
void primefactors(ll num){
          while(num%2==0){
		 num = num/2;
        vec[2]= (vec[2]+1)%MOD;
	    }

	 for(int i=3;i<=sqrt(num);i+=2){
		 if(num % i == 0){
			 num = num/i;
			 vec[i]= (vec[i]+1)%MOD;
		 }
	 }

	 if(num>2){
	     vec[num]= (vec[num]+1)%MOD;
     }
}

int main() {
    ll t,n;
	cin>>t;
	while(t--){
       for(ll i=0;i<vec.size();i++)
            vec[i]=0;
		cin>>n;
	    vector<ll>a(n);
		for(ll i=0;i<n;i++){
			ll x;
			cin>>x;
			primefactors(x);
		}
		 ll product =1;
		for(ll i=0; i<vec.size();i++){
		if(vec[i]!=0)
		    product = ((product%MOD)*((vec[i]+1)%MOD))%MOD;
	     }
       cout<<product<<endl;

	}

	return 0;
}
