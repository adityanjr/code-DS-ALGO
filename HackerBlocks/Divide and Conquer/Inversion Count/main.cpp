#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
ll t;
ll L[100005];

ll mergesort(ll arr[],ll low, ll high){

       if(low>=high)
            return 0;
       ll count = 0;
       ll mid = low+ (high-low)/2;

       count = count + mergesort(arr,low,mid) + mergesort(arr,mid+1,high);
       ll i=low;
       ll j=mid+1;
       ll k = low;
       while(i<=mid && j<=high){
           if (arr[i]<=arr[j])
        {
            L[k++]=arr[i++];
        }
        else
        {
            L[k++]= arr[j];
            count += (mid - i+1);
            j++;
        }
       }

       while(i<=mid){
        L[k++] = arr[i++];
       }

       while(j<=high){
        L[k++] = arr[j++];
       }

       for(int i=low;i<=high;i++){
        arr[i] = L[i];
       }

       return count;
}

int main() {
    cin>>t;
    while(t--){
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<mergesort(arr,0,n-1)<<endl;
    }
}
