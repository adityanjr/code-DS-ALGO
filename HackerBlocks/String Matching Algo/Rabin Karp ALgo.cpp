#include <bits/stdc++.h>
using namespace std;

int hashFunc(string s){  // hash function return a hash value as the sum of ascii values of string. 
    int val = 0;
    for(int i=0;i<s.length();i++){
        val += s[i];
    }
    return val;
}

bool rabinkarp(string s1, string s2){
        bool sucess = true;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i])
              return false;
        }
        return sucess;
}

int main() {
    
    string s1,s2;
    cin>>s1>>s2;
    int hashofsub = hashFunc(s2);
    int hashofstring= hashFunc(s1.substr(0,s2.length()));
    if(hashofsub == hashofstring){
        if(rabinkarp(s1.substr(0,s2.length()),s2)){
            cout<<"Found a substring at: "<<1<<endl;
        }
    }

    for(int i=1;i<=(s1.length()-s2.length());i++){
        hashofstring = hashofstring - s1[i-1] + s1[i];
        if(hashofstring == hashofsub){
           bool sucess = rabinkarp(s1.substr(i,i+s2.length()),s2);
           if(sucess)
                cout<<"Found a substring at: "<<i+1<<endl;
        }
    }
    return 0;
}
