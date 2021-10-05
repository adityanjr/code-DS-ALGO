#include <iostream>
#include <climits>
using namespace std;
#define ll long long

int main(){
    ll n = 5;
    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll sum = 0;
    ll maxEle = INT_MIN;
    ll minEle = INT_MAX;

    for(int i=0; i<n; i++){
        sum += arr[i];
        if(arr[i]>maxEle){
            maxEle = arr[i];
        }
        if(arr[i]<minEle){
            minEle = arr[i];
        }
    }
    ll maxSum = sum - minEle;
    ll minSum = sum - maxEle;

    cout<<minSum<<" "<<maxSum;
}
