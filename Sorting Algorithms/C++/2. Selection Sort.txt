#include<bits/stdc++.h>
using namespace std;

int main() {
    long long arr[10000];
    int n, k;
    cin>>n;
    for(k=0; k<=n; k++){
        cin>>arr[k];
    }
    
    int min_index = 0;
    for(int i=0; i<n-1; i++){
        min_index = i;
        for(int j=i; j<n; j++){
            if(arr[min_index]>arr[j]){
                min_index=j;
            }
        }
        swap(arr[min_index], arr[i]);
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
	return 0;
}