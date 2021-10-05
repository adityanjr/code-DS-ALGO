#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n; cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int maxEle = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>maxEle)
            maxEle = arr[i];
    }
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==maxEle)
            count++;
    }
    cout<<count;
}