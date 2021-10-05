#include<bits/stdc++.h>
using namespace std;

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

int compare(int a, int b){
	return a<=b;
}

int main(){
	c_p_c();

	int coins[6]={100,50,10,5,2,1};
    t(x){
    	int money, count=0;
    	cin>>money;
    	f(0,5){
    		if(money>=coins[i]){
    			money -= coins[i];
    			count++;
    			i--;
    		}
    	}
    	cout<<count<<endl;
    }

	return 0;
}