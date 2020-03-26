#include <bits/stdc++.h>
using namespace std;

int main()
{   int t;
    cin>>t;
    while(t--){
    string s;
    int n;
    cin>>n;
    cin>>s;
    long long int ones = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1')
            ones++;
    }
    cout<<(ones*(ones+1))/2<<endl;
    }
    return 0;
}
