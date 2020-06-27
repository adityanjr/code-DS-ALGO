/*
 *This problem was asked by Amazon.

    There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. 
    
    Given N, write a function that returns the number of unique ways you can climb the staircase. 
    
    The order of the steps matters.

    For example, if N is 4, then there are 5 unique ways:

    1, 1, 1, 1
    2, 1, 1
    1, 2, 1
    1, 1, 2
    2, 2

    What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number 
    from a set of positive integers X? 
    
    For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
    

   */ 
#include <bits/stdc++.h>
using namespace std;
int main(void){
    int x; // number of stairs can be climbed 
    cin>>x; // 2 by default
    vector<int>possible(x);
    for(auto &itr:possible){
        cin>>itr;
    }
    int n; // final stair
    cin>>n;
    vector<int>dp(n+2);
    for(int i=1;i<=n;++i){
        dp[i]=0;
        for(auto &itr:possible){
            if(itr==i){
                dp[i]+=1;
            }
            if(itr>i){
                break;
            }
            dp[i]+=(i-itr>=0)?dp[i-itr]:0;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
