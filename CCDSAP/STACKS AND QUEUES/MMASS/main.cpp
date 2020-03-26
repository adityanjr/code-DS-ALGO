#include <bits/stdc++.h>
using namespace std;

int value(char ch){
    if(ch=='C')
        return 12;
    else if(ch=='H')
        return 1;
    else
        return 16;
}
int main()
{
    string s;
    cin>>s;
    stack<int>ss;

    for(int i=0;i<s.length();i++){
        if(s[i]=='C' || s[i]=='O'|| s[i]=='H'){
            ss.push(value(s[i]));
        }
        else if(s[i]=='('){
                    ss.push(-1);
         }
         else if( 48<= s[i] && s[i]<=57){
            int val = ss.top();
            ss.pop();
            ss.push((s[i]-48)*val);
         }
         else {
            int val = 0;
            while(ss.top()!=-1){
                val += ss.top();
                ss.pop();
            }
            ss.pop();
            ss.push(val);
         }
    }
    int ans = 0;
    while(!ss.empty()){
        ans += ss.top();
        ss.pop();
    }
    cout<<ans<<endl;
    return 0;
}
