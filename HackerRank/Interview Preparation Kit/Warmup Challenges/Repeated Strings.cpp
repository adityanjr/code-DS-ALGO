#include <iostream>
#include <string>
using namespace std;
#define ll long long

int main(){
    string s;
    ll n, count = 0;
    cin>>s>>n;
    int len = s.length();
    for(int i=0; i<len; i++) {
        if(s[i]=='a') count++;
    }
    count = count*(n/len);
    for(int i=0; i<n%len; i++) {
        if(s[i]=='a') count++;
    }
    cout<<count<<endl;
}