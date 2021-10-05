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
		int n;
		cin>>n;
		int arr[n];
		f(0,n-1){
			cin>>arr[i];
		}
		int count=0;
		f(0,n-1){
			int sum=0, product=1;
			for(int j=i; j<n; j++){
				sum = sum+arr[j];
				product *= arr[j];
				if(sum==product){
					count++;
				}
			}
		}
		cout<<count<<endl;
	}

	return 0;

}