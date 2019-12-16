#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string s, string s1){
 if(s[0]==s1[0])
    return s.length()>s1.length(); // descending order.
 else
   return s<s1; // ascending order.
}
int main() {
	int n;
    cin>>n;
    string s;
    string str[n];
    for(int i=0;i<n;i++){
        cin>>s;
        str[i]=s;
    }
    sort(str,str+n,compare);
    for(int i=0;i<n;i++){
        cout<<str[i]<<endl;
    }
}