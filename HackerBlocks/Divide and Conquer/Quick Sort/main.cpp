#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll partitionpoint(ll arr[], ll left, ll right, ll pivot){
     ll leftpointer =  left;
     ll rightpointer =  right - 1;

     while(true){
         while(leftpointer<right && arr[leftpointer]<pivot)
             leftpointer++;
        while(rightpointer>left && arr[rightpointer]>pivot)
             rightpointer--;
        if(leftpointer>=rightpointer)
          break;
        else{
            swap(arr[leftpointer],arr[rightpointer]);
        }
     }
     swap(arr[leftpointer],arr[right]);

     return leftpointer;

}


void quicksort(ll arr[], ll left, ll right){
    if(left<right){

     srand(time(NULL));
     ll random = left + rand()%(right-left);
     swap(arr[random],arr[right]);
     ll pivot = arr[right];
     ll partition = partitionpoint(arr,left,right,pivot);
     quicksort(arr,left,partition-1);
     quicksort(arr,partition+1,right);

    }
}
int main() {
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
     cin>>arr[i];
    quicksort(arr,0,n-1);

    for(ll i=0;i<n;i++)
       cout<<arr[i]<<" ";

	return 0;
}
