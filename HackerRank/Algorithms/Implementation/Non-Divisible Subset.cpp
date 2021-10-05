#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int freq[k]={0};
    for(int i=0;i<n;i++){
        freq[arr[i]%k]++;
    }
    int c=min(freq[0],1);
    for(int i=1; i<k/2+1; i++){
        if(i!=k-i) {
            c+=max(freq[i],freq[k-i]);
        }
    }
    if(k%2==0) c++;
    cout<<c;
    return 0;
}
