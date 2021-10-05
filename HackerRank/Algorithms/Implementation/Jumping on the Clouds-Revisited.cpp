#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int k; cin>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int energy = 100;
    int i=0;
    while(i<n){
        energy--;
        if(arr[i]==1){
            energy -= 2;
        }
        i = (i+k)%n;
        if(i==0){
            break;
        }
    }
    cout<<energy;
}
