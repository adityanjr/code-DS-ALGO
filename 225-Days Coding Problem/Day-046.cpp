/*
   
   This problem was asked by Amazon.

   Given a string, find the longest palindromic contiguous substring. If there are more than one with the maximum length, return any one.

   For example, the longest palindromic substring of "aabcdcb" is "bcdcb". The longest palindromic substring of "bananas" is "anana".

 */
#include <bits/stdc++.h>
using namespace std;
inline bool palin(string ans){
    int i=0 , j=(int)ans.size()-1;
    while(i<j){
        if(ans[i]!=ans[j])
            return false;
        i++;
        j--;
    }
    return true;
}
inline string sol(string ans){
    if(ans.size()==0)
        return "";
    if(palin(ans)){
        return ans;
    }
    string left = sol(ans.substr(0,(int)ans.size()-1));
    string right = sol(ans.substr(1,(int)ans.size()-1));
    if(left.size()>right.size()){
        return left;
    }else{
        return right;
    }
    assert(false);
}
int main(void){
    string s;
    cin>>s;
    cout<<sol(s)<<'\n';
    return 0;
}
