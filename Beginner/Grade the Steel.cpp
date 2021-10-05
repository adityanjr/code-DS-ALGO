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
		int hardness, tensile;
		float carbon;
		cin>>hardness>>carbon>>tensile;

		bool a = hardness>50;
		bool b = carbon<0.7;
		bool c = tensile>5600;

		if(a && b && c) cout<<10<<endl;
		else if (a && b && !c) cout<<9<<endl;
		else if(!a && b && c) cout<<8<<endl;
		else if(a && !b && c) cout<<7<<endl;
		else if(!a && !b && !c) cout<<5<<endl;
		else cout<<6<<endl;
    }

	return 0;
}