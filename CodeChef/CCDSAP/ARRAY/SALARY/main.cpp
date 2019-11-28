#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        long long int sum = 0;
        for(int i=0;i<n;i++)  cin>>arr[i];
        sort(arr,arr+n);
        while(arr[0]!=arr[n-1]){
            int temp = arr[n-1] - arr[0];
            for(int i=0;i<n-1;i++)
                arr[i] += temp;
            sort(arr,arr+n);
            sum += temp;
        }
        cout<<sum<<endl;
    }
    return 0;
}
