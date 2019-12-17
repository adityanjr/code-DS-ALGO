#include <iostream>
using namespace std;
#define ll long long int

int main()
{   ll n;
    cin>>n;
    ll arr[n];
    bool zero = false;
    bool n_is_even = true;

    if(n&1)
        n_is_even = false;

    ll negCounter =0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==0)
            zero = true;
        if(arr[i]<0)
             negCounter++;
    }
    if(n_is_even){
         for(int i=0;i<n;i++){
            if(arr[i]>=0)
                arr[i]= -arr[i] - 1;
         }
    }
    else{
        if(negCounter%2!=0){
            for(int i=0;i<n;i++)
                arr[i] = -arr[i] - 1;
        }

        if(negCounter%2==0){
             ll temp = n-negCounter;
             ll i=0;
             while(temp>1){
                while(i<n){
                    i++;
                    if(arr[i]>=0){
                        arr[i] = -arr[i] - 1;
                        break;
                    }

                }
                temp = temp-1;
             }
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
