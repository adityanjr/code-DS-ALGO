#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n,x;
    int arr[1000];
    cin>>n;
    for(int index=0; index<n; index++){
        cin>>x;
        arr[index]=x;
    }
    sort(arr,arr+n);
    int target;
    cin>>target;

    for(int i=0; i<n-1; i++){
        int left=i+1, right=n-1;
        while(left<right){
            if(arr[left]+arr[right]+arr[i]==target){
                cout<<arr[i]<<", "<<arr[left]<<" and "<<arr[right]<<endl;
                left++;
                right--;
            }
            else if(arr[left]+arr[right]+arr[i]<target){
                left++;
            }
            else right--;
        }
    }
	return 0;
}