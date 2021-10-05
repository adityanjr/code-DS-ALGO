#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans=INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j]){
                ans = min(ans, abs(j-i));
            }
        }
    }
    if(ans==INT_MAX){
        cout<<-1;
    }
    else cout<<ans;
}
