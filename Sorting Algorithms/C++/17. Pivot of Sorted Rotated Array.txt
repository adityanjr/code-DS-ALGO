#include<iostream>
using namespace std;
int findmax(int arr[],int start,int ends){
    while(start <= ends){
        int mid = (start + ends)/2;
        if(arr[mid]>arr[mid+1])
            return mid;
        else if(arr[mid] < arr[mid-1])
            return (mid-1);
        else if(arr[mid] > arr[ends])
            start = mid + 1;
        else if(arr[start] > arr[mid])
            ends = mid - 1;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int pivot = findmax(arr,0,n-1);
    cout<<pivot<<endl;
    return 0;
}