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

    int n; cin>>n;
    ll A1=0, A2=0, l1=0, l2=0;
    while(n--)
    {
        int a1,a2;
        cin>>a1>>a2;
        A1=A1+a1;
        A2=A2+a2;
        if(A1>A2 && l1<(A1-A2))
            l1=A1-A2;
        else if(A2>A1 && l2<(A2-A1))
            l2=A2-A1;
    }
    if(l1>l2){
    	cout<<1<<" "<<l1;
    } else{
    	cout<<2<<" "<<l2;
    }

	return 0;
}