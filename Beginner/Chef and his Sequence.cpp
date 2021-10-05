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

		int n, c=0; cin>>n;
		int a[n];
		f(0,n-1){
			cin>>a[i];
		}
		int f; cin>>f;
		int b[f];
		f(0,n-1){
			cin>>b[i];
		}
        f(0,f-1){
        	for(int j=0; j<n; j++){
	            if(a[j]==b[i]){
	                c++;
	                break;
	            }
            }
        }	    
	    
	    if(c==f)
	    	cout<<"Yes\n";
	    else
	    	cout<<"No\n";
	}

	return 0;

}