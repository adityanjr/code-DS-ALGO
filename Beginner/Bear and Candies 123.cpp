#include<bits/stdc++.h>
using namespace std;

// Author - ADITYA SINGH (https://github.com/adityanjr)

#define ll              long long
#define pb              push_back
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n)       int *arr=new int[n];
#define t(x)            int x; cin>>x; while(x--)
#define f(x,y)          for(int i=x; i<=y; i++)


void c_p_c(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main(){
	c_p_c();

	t(x){

		int a, b;
		cin>>a>>b;
		int i=1;
		int sumA=0, sumB=0;
		while(i>0){
			if(sumA>a || sumB>b) break;
			sumA = sumA + (2*i-1);
			sumB = sumB + (2*i);
			i++;
		}
		if(sumA>a){
			cout<<"Bob\n";
		}
		else cout<<"Limak\n";
	}

	return 0;

}