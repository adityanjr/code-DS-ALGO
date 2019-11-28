#include <bits/stdc++.h>
using namespace std;
//7:47
int main()
{
    int k=0;
    while(1){
        string s;
        cin>>s;
        stack<char>ss;
        if(s[0]=='-')
            break;

        int i=0;
        int len =  s.length();
        while(i<len){
            if(s[i]=='{'){
                ss.push(s[i]);
                i++;
            }
            else{
                if(!ss.empty() && ss.top()=='{'){
                    ss.pop();
                    i++;
               }
              else {
                    ss.push(s[i]);
                    i++;
                }
            }
        }

     int ans = 0;
     while(!ss.empty()){
        char str =  ss.top();
        ss.pop();
        if(!ss.empty() && ss.top()==str){
            ans++;
            ss.pop();
        }
        else{
            ans+=2;
            ss.pop();
        }
     }
     cout<<k+1<<". "<<ans<<endl;
     k++;
    }
    return 0;
}
