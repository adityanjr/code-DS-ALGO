#include <iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        int c[n];
        int l[n];

        for(int i=0;i<n;i++) cin>>c[i];
        for(int i=0;i<n;i++) cin>>l[i];

        ll mini = INT_MAX;
        ll sum = 0;
        for(int i=0;i<n;i++){
            if(mini>c[i])
                mini = c[i];

            sum += mini*l[i];
        }
        cout<<sum<<endl;
    }
     return 0;
}
