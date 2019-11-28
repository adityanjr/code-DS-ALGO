#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s[100];
    bool ss[100]={false};
        for(int i=0;i<n;i++) cin>>s[i];

        for(int i=0;i<k;i++){
            int l;
            cin>>l;
            for(int j=0;j<l;j++){
                string str;
                cin>>str;
                //cout<<"string input:"<<str<<endl;
                for(int k=0;k<n;k++){
                    if(str == s[k]){
                        ss[k] = true;
                    }
                }
            }
        }

        for(int i=0;i<n;i++) {
            if(ss[i])
                cout<<"YES"<<" ";
            else
                cout<<"NO"<<" ";
        }

        cout<<endl;
    }
    return 0;
}
