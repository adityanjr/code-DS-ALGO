#include <iostream>
using namespace std;

bool isCancelled(int *arr, int n, int k){
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i]<=0){
            count++;
        }
    }
    if(count < k){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int k; cin>>k;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        if(isCancelled(arr, n, k)){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
}