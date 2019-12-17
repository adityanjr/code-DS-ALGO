#include <bits/stdc++.h>
using namespace std;
// O(n.m) n is the size of string in which we have to find a substr of length m

void navieAlgo(string s1,string s2){
    for(int i=0;i<=(s1.length()-s2.length());i++){
        int j;
        for(j=0;j<s2.length();j++){
            if(s1[i+j]!=s2[j])
              break;
        }
        if(j==s2.length())
          cout<<"Found a match at: "<<i+1<<endl;
    }
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    navieAlgo(s1,s2);
}
