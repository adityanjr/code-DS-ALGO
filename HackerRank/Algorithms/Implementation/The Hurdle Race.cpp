#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n; cin>>n;
    int k; cin>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int max = INT_MIN;

    for(int i=0; i<n; i++){
        if(max < arr[i]) max= arr[i];
    }
    if(max>k){
        cout<<max-k;
    }
    else cout<<0;
}