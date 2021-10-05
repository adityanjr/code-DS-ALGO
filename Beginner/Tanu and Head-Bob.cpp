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
		int k,n=0,ii=0,y=0;
        cin>>k;
        string s;
        cin>>s;
        for(int i=0; i<k; i++){
            switch(s[i])
            {
                case 'N':n++;break;
                case 'Y':y++;break;
                case 'I':ii++;break;
            }
        }
        if(y!=0)
            cout<<"NOT INDIAN\n";
        else if(ii!=0)
            cout<<"INDIAN\n";
        else
            cout<<"NOT SURE\n";
    }

	return 0;
}
--------------------------------------------------------
/*
int main(){
	c_p_c();

	t(x){
		int n; cin>>n;
        string s; cin>>s;
        int found = 0;
        string res = "";
		for(int i=0; i<s.length(); ++i)
	        if (s[i] != 'N'){
			      if(s[i] == 'Y') res = "NOT INDIAN\n";
			      else if (s[i] == 'I') res = "INDIAN\n";
			found = 1;
			break;
		}
		if(found==0)
		    res = "NOT SURE\n";

		cout<<res;
    }

	return 0;
}
*/