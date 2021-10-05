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

bool printPairs(int arr[], int n, int sum) 
{ 
    int count = 0;
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] + arr[j] == sum) 
                return true;

    return false;        
} 

int main(){
	c_p_c();

	t(x){
		ll a,b,c,d;
        cin>>a>>b>>c>>d;

        if(a==b && c==d) cout<<"YES\n";

        else if(a==c && b==d) cout<<"YES\n";

        else if(a==d && b==c) cout<<"YES\n";

        else cout<<"NO\n";
	}
	
	return 0;
}