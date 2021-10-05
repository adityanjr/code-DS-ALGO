#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    map<string,string> m;
    long n; cin>>n;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        string x; cin>>x;
        m.insert({s,x});
    }
    while(cin>>s){
        if(m.find(s)!=m.end()){
            cout<<s<<"="<<m[s]<<endl;
        }
        else cout<<"Not found"<<endl;
    }
    return 0;
}