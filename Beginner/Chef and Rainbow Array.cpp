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
		int n,a[105];
	    cin>>n;
	    bool flag=true;

	    for(int i=1;i<=n;i++){
            cin>>a[i];
	    }
	    if((a[n/2+1]!=7)||a[1]!=1) flag=false;
	    else {
        	for(int i=1;i<=n/2;i++){
            	int dif=a[i+1]-a[i];
            	if(!((a[i]==a[n-i+1])&&(dif==1||dif==0))){
                	flag=false;
                	break;
                }
            }
        }
        if(flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
	}

	return 0;

}