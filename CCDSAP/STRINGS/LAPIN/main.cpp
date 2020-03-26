#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int length  = s.length();
        int limit1, start2;
        if(length&1){
            limit1 = (length/2);
            start2 = (length/2)+1;
        }
        else{
             limit1 = length/2;
             start2 = length/2;
        }
        unordered_map<char,int>h;
        unordered_map<char,int>h1;

        for(int i=0;i<limit1;i++){
            h[s[i]]++;
        }
        for(int i=start2;i<length;i++){
            h1[s[i]]++;
        }

        if(h==h1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
