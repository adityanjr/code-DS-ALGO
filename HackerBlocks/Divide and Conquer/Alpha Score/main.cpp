#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll alphascore =  0;
ll arr[100005]={0};
void merge(ll start, ll mid , ll end){

   ll n1 = mid - start + 1;
   ll n2 = end - mid;
   ll L[n1],R[n2];
   ll i=0;
   ll j=0;
   ll k=start;

   for(i=0;i<n1;i++){
      L[i] =  arr[start + i];
   }

   for(j=0;j<n2;j++){
       R[j] = arr[mid+j+1];
   }

   i=0;
   j=0;
   ll sum = 0;
   while(i<n1 && j<n2){
       if(L[i]<R[j]){
           arr[k] = L[i];
           sum= (sum%MOD+ L[i]%MOD)%MOD;
           i++;
       }
       else{
           arr[k]=R[j];
           alphascore = (alphascore%MOD + sum%MOD)%MOD;
           j++;
       }
       k++;
   }

   while(i<n1){
     arr[k] = L[i];
     i++;
     k++;
   }

   while(j<n2){
     alphascore = (alphascore%MOD + sum%MOD)%MOD;
     arr[k] = R[j];
     j++;
     k++;
   }

}
void mergesort(ll l, ll r){
    if(l<r){
        ll mid = l + (r-l)/2;
        mergesort(l,mid);
        mergesort(mid+1,r);
        merge(l,mid,r);
    }
}

int main() {
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(0,n-1);
    cout<<alphascore%MOD<<endl;
	return 0;
}
