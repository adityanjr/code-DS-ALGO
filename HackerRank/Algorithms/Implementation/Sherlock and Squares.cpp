#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        int x = ceil(sqrt(a));
        int y = floor(sqrt(b));
        cout<<(y-x)+1<<endl;
    }
}