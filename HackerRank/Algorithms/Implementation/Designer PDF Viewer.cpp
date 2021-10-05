#include <iostream>
#include <cstring>
using namespace std;

int main(){

    int heights[26];
    for(int i=0; i<26; i++){
        cin>>heights[i];
    }
    string s;
    cin>>s;
    int maxheight = 0;
    for(int i=0; i<s.length(); i++){
        maxheight = max(maxheight, heights[s[i]-'a']);
    }
    cout<<maxheight*s.length();
}