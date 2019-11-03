#include<bits/stdc++.h>
using namespace std;

int main() {
    long long arr[10000];
    int n, k;
    cin>>n;
    for(k=0; k<=n; k++){
        cin>>arr[k];
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
	return 0;
}