/*
 * This problem was asked by Facebook.  
 * Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.  
 *
 * For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.  
 * 
 * You can assume that the messages are decodable. For example, '001' is not allowed.
 *
 */

// idea is use dynamic programming 

#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    vector<int>dp(s.size()+1,0);
    for(int i=0;i<=(int)s.size();++i){
        if(i==0){
            dp[i] = 1;
            continue;
        }
        if(s[i]!=0){
            dp[i]=dp[i-1];
        }
        int x = s[i-1]-'0';
        x*=10;
        x+=(s[i]-'0');
        if(x>=10 and x<=26){
            dp[i]+=((i-2)>=0)?dp[i-2]:1;
        }
    }
    cout<<dp[s.size()-1]<<endl;
    return 0;
}
