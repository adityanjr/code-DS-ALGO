#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int freq[101] = {0};
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }

    int result=0;
    for(int i=1; i<100; i++){
        result = max(result, freq[i]+freq[i-1]);
    }
    cout<<result;
}