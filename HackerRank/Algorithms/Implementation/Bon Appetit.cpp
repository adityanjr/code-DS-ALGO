#include <iostream>
using namespace std;

int main(){
    
    int n, item;
    cin>>n>>item;
    int bill[n];
    for(int i=0; i<n; i++){
        cin>>bill[i];
    }
    int charged;
    cin>>charged;

    int sum=0;
    for(int i=0; i<n; i++){
        sum+= bill[i];
    }
    int actual = (sum - bill[item])/2;

    (charged == actual) ? cout<<"Bon Appetit" : cout<<charged-actual;
}