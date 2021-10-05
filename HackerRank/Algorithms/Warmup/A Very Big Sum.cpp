#include <iostream>
using namespace std;
#define ll long long int

int main(){
    int n;
    ll arr[10];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    cout<<sum;
}