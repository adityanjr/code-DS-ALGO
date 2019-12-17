#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<string>v;
char arr[27]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void Codesofthestring(string str,string s, int len, int pos){
    if(pos==len){
        v.push_back(s);
        return;
    }

    if(pos+1<=len){
     int val = str[pos] - '0';
     s.push_back(arr[val]);
     Codesofthestring(str,s,len,pos+1);
    }
    s.pop_back();
    int val =  (str[pos] - '0')*10;
    val += str[pos+1] - '0';
    if(pos+2<=len && val<=26 ){
      s.push_back(arr[val]);
      Codesofthestring(str,s,len,pos+2);
    }
}
int main()
{
    string str;
    string s;
    int i;
    cin>>str;
    ll len = str.size();
    Codesofthestring(str,s,len,0);
    cout<<"[";
    for( i=0;i<v.size()-1;i++){
        cout<<v[i]<<", ";
    }
    cout<<v[i];
    cout<<"]"<<endl;
    return 0;
}
