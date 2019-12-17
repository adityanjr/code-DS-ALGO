#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<int>vec(1000001);
vector<int>divisors;
vector<int>v;

void primefactors(ll num){
     while(num%2==0){
		 num = num/2;
         vec[2]++;
	    }

	 for(int i=3;i<=sqrt(num);i+=2){
		 if(num % i == 0){
			while(num%i==0){
			 num = num/i;
			 vec[i]++;
			}
		 }
	 }

	 if(num>1){
	     vec[num]++;

     }
}

void generateprimes(){
    vector<bool>p(100000001,false);
	p[0]=p[1]=0;
	p[2]=1;
	v.push_back(2);
	for(ll i=3;i<=100000001;i+=2){
		p[i]=1;
	}
	for(ll i=3;i<=100000001;i+=2){
		if(p[i]){
            v.push_back(i);
			for(ll j=i*i;j<=100000001;j+=2*i){
				  p[j]=0;
			}
		}
	}
}

ll fastexponentiation(ll a, ll b){
    if(b==0)
         return 1;
    ll power = fastexponentiation(a,b/2);
    power *= power;

    if(b&1)
        power *= a;
    return power;
}

void generatedivisors(ll num1){
    for(int i=2;i<=sqrt(num1);i++){
        if(num1%i==0){
            if(num1/i!= sqrt(num1)){
                divisors.push_back(i);
                divisors.push_back(num1/i);
            }
            else
                divisors.push_back(i);
        }
    }
    divisors.push_back(num1);
}

int main() {
    ll num1=1,x;
    cin>>x;
    generateprimes();
    for(int i=0;i<x;i++){
       ll val;
       cin>>val;
       num1 *= fastexponentiation(v[i],val);
    }
    generatedivisors(num1);
    for(ll i=0;i<divisors.size();i++){
        primefactors(divisors[i]);
    }
        ll product =1;
    for(ll i=0; i<vec.size();i++){
        product = product*(vec[i]+1);
        product %= MOD;
        vec[i]=0;
        }
    cout<<product%MOD<<endl;
	return 0;
}
