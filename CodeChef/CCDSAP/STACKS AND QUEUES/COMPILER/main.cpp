#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        stack<char>ss;
        int ans =0;
        int i =0;
        bool flag = true;
        for(i=0;i<s.length();i++){
            if(s[i]=='<'){
                ss.push(s[i]);
            }
            else{
                if(!ss.empty()){
                    ss.pop();
                }
                else
                {
                  flag = false;
                  break;
                }
            }

            if(ss.empty()){
                ans = max(i+1,ans);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
