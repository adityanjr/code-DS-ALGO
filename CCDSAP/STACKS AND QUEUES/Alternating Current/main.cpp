#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char>ss;
    string s;
    cin>>s;

    int i = 0;
    int len =  s.length();

    while(i<len){
        if(ss.empty()){
            ss.push(s[i]);
            i++;
        }
        else {
             if(ss.top()!=s[i]){
                ss.push(s[i]);
                i++;
              }
             else{
                ss.pop();
                i++;
             }
        }
    }

    if(ss.empty())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
