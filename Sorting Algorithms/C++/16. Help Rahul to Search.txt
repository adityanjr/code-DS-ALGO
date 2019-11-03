#include<iostream>
using namespace std;

int searchIn(int *arr, int low, int high, int key){
    if(low>high) return -1;
    int mid =low + (high - low)/2;
    if(arr[mid]==key) 
        return mid;
    if(arr[low]<=arr[mid]){
        if(key>=arr[low] && key<=arr[mid])
            return searchIn(arr, low, mid-1, key);
        else
            return searchIn(arr, mid+1, high, key);    
    }
    if(key>=arr[mid] && key<=arr[high])
        return searchIn(arr, mid+1, high, key);
    return searchIn(arr, low, mid-1, key);    
}
int main() {
    int n, key;
    int arr[1000005];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>key;
    cout<<searchIn(arr,0,n-1,key);
	return 0;
}