#include <iostream>
using namespace std;

int height(int n){
    int currHeight = 0;
    for(int i=0; i<=n; i++){
        if(i%2==0){
            currHeight += 1;
        }
        else {
            currHeight *= 2;
        }
    }
    return currHeight;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<height(n)<<endl;
    }
}