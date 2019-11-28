#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    string s;
    ll t;
    cin>>t;
    while(t--){
        cin>>s;
        ll count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')
              count++;
        }
        if(count&1)
           cout<<"WIN"<<endl;
        else
          cout<<"LOSE"<<endl;
        s.clear();
    }
	return 0;
}

