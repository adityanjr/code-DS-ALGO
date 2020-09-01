/*
   This problem was asked by Quora.

   Given a string, find the palindrome that can be made by inserting the fewest 
   number of characters as possible anywhere in the word.

   If there is more than one palindrome of minimum length that can be made,
   return the lexicographically earliest one (the first one alphabetically).

   For example, given the string "race", you should return "ecarace", 
   since we can add three letters to it (which is the smallest amount to make a palindrome).

   There are seven other palindromes that can be made from "race" by adding three letters, but "ecarace" comes first alphabetically.

   As another example, given the string "google", you should return "elgoogle".
  
 */

#include <bits/stdc++.h>
using namespace std;
bool palin(string s){
    int i=0 , j=(int)s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;j--;
    }
    return true;
}
string get_palin(string s){
    if(palin(s)){
        return s;
    }
    if(s[0]==s[s.size()-1]){
        return s[0]+get_palin(s.substr(1,s.size()-1))+s[s.size()-1];
    }else{
        string left = s[0]+get_palin(s.substr(1,s.size()))+s[0];
        string right = s[s.size()-1]+get_palin(s.substr(0,s.size()-1))+s[s.size()-1];
        if(left.size()>right.size()){
            return right;
        }else if(left.size()<right.size()){
            return left;
        }
        if(left>right){
            return right;
        }else{
            return left;
        }
    }
}
int main(void){
    string s , rev; 
    cin >> s;
    cout<<get_palin(s)<<'\n';
    return 0;
}
