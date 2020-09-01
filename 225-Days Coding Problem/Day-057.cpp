/*
   This problem was asked by Amazon.

   Given a string s and an integer k, break up the string into multiple lines such that each line has a length of k or less.
   You must break it up so that words don't break across lines. 
   Each line has to have the maximum possible amount of words. If there's no way to break the text up, then return null.

   You can assume that there are no spaces at the ends of the string and that there is exactly one space between each word.

   For example, given the string "the quick brown fox jumps over the lazy dog" and k = 10,
   you should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"]. No string in the list has a length of more than 10.
 */
#include <bits/stdc++.h>
using namespace std;
/*
 * we will choose each word greedily.
 */
vector<string>ans;
bool sol(string &s , const int &k){
    stringstream ss(s);
    string temp; 
    while(ss>>s){
        if(s.size()>k) return false; // this can't be adjusted to given word limits 
        if(temp.size()+s.size()+1<=k){
            if(temp.size()==0){
                temp+=s;
            }else{
                temp+=" "+s;
            }
        }else{
            ans.push_back(temp);
            temp =s;
        }
    }
    if(temp.size()>0){
        ans.push_back(temp);
    }
    return true; // if answer possible then return true
}
int main(void){
    string s = "the quick brown fox jumps over the lazy dog"; 
    int k = 10;
    if(sol(s ,k)){
        for(auto &itr:ans){
            cout<<itr<<'\n';
        }
    }else{
        cout<<"Not Solvable"<<'\n';
    }
    ans.clear(); 
    cout<<"\n\n\n";
    s = "A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream.";
    k = 12;
    if(sol(s ,k)){
        for(auto &itr:ans){
            cout<<itr<<'\n';
        }
    }else{
        cout<<"Not Solvable"<<'\n';
    }

    ans.clear(); 
    cout<<"\n\n\n";
    s = "a b c d e f g h i j k l m n o p q";
    k = 14;
    if(sol(s ,k)){
        for(auto &itr:ans){
            cout<<itr<<'\n';
        }
    }else{
        cout<<"Not Solvable"<<'\n';
    }
    return 0;
}
