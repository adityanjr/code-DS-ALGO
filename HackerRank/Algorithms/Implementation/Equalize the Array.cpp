#include <cstdint>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    int freq[101]={0};
    for(int i=0; i<n; i++){
        cin>>arr[i];
        freq[arr[i]]++;
    }
    
    int max = INT16_MIN;
    for(int i=1; i<=100; i++){
        if(freq[i]>max) max = freq[i];
    }
    cout<<n-max;
}