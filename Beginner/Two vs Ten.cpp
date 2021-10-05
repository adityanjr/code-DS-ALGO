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
		int n;
		cin>>n;
		if(n%10==0) cout<<0<<endl;
		else if(n%5==0) cout<<1<<endl;
		else cout<<-1<<endl;
	}
	
	return 0;
}