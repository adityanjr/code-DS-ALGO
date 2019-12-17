#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void classAssignment(ll a[], ll b[], ll n){
	if(n==1){
		a[1]=1;
		b[1]=1;
		return;
	}
   classAssignment(a,b,n-1);
   a[n]=a[n-1]+b[n-1];
   b[n]=a[n-1];
}
int main() {
	ll t, n;
	ll a[45],b[45];
	classAssignment(a,b,44);
	cin>>t;
    int val = 1;
	while(t--){
		cin>>n;
		cout<<"#"<<val++<<" : "<<a[n]+b[n]<<endl;
	}
	return 0;
}
