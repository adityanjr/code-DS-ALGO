#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

    int t; cin>>t;
    while(t--){
        int x, y, z;
        cin>>x>>y>>z;
        if(abs(x-z)==abs(y-z)){
            cout<<"Mouse C"<<endl;
        }
        else if(abs(x-z)<abs(y-z)){
            cout<<"Cat A"<<endl;
        }
        else {
            cout<<"Cat B"<<endl;
        }
    }
}