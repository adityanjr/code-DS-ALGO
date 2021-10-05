#include <iostream>
using namespace std;

int handshake(int n){
    int ans = (n*(n-1))/2;  //nC2 total handshakes
    return ans;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<handshake(n)<<endl;
    }
}