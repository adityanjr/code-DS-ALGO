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

	int n, k, open=0;
	cin>>n>>k;
	int arr[n]={0};
	f(0,k-1){
		string s; 
		cin>>s;
		if(s == "CLICK"){
			int x;
			cin>>x;
			arr[x-1] = !arr[x-1];
			if(arr[x-1] == 0) open--;
	        else open++;
		}
		else{
			f(0,n-1){
				arr[i]=0;
			}
			open=0;
		}
		cout<<open<<endl;
	}
	
	return 0;
}