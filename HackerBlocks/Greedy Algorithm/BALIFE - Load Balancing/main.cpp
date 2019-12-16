#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    while(true){
        int n;
        cin>>n;
        if(n==-1){
            break;
        }
        int arr[9000]={0};
        long long int sum = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum += arr[i];
        }

        if(sum%n){
            cout<<"-1"<<endl;
            continue;
        }
        int avg = sum/n;
        for(int i=0;i<n;i++){
            arr[i] = arr[i] - avg;
        }

        for(int i=1;i<n;i++){
            arr[i] +=arr[i-1];
        }
        int ans  = INT_MIN;
        for(int i=0;i<n;i++){
            ans =  max(ans,abs(arr[i]));
        }
        cout<<ans<<endl;

    }
    return 0;
}
