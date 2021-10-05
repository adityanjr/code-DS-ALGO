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

int main(){
	c_p_c();

	t(x){
		int m,x,y;
		cin>>m>>x>>y;
		int range=x*y;
		int arr[101]={0};
		int free=0;
		while(m--){
			int house;
			cin>>house;
			int s= house-range < 0 ? 0 : house-range;
            int e= house+range >100 ? 100 : house+range;
			f(s,e){
				arr[i]++;
			}
		}
		f(1,100){
			if(arr[i]==0) free++;
		}
		cout<<free<<endl;
	}
	
	return 0;
}