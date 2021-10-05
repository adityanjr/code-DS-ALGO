#include <iostream>
#include <string>
using namespace std;

bool isConvertible(string s1, string s2, int k){
    int l1 = s1.length();
    int l2 = s2.length();
    if((l1+l2)<=k){
        return true;
    }
    int commonLen = 0;
    int minLen = min(l1,l2);
    for(int i=0; i<minLen; i++){
        if(s1[i]==s2[i]){
            commonLen++;
        }
        else{
            break;
        }
    }
    int ops = (l1-commonLen)+(l2-commonLen);
    if((k-ops)%2 == 0 && k>=ops){ 
        return true;
    }
    return false;
} 
int main(){
    string s1, s2;
    cin>>s1>>s2;
    int k; cin>>k;
    if(isConvertible(s1, s2, k)){
        cout<<"Yes";
    }
    else {
        cout<<"No";
    }
}
