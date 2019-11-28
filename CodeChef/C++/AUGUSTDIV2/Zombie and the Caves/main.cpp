#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>c(n);
        vector<int>h(n);
        for(int i=0;i<n;i++)
            cin>>c[i];

        for(int i=0;i<n;i++)
              cin>>h[i];

        vector<int>rad(n,0);
        int aux[n]={0};
        for(int i=0;i<n;i++){
            int low = i-c[i];
            int high = i+c[i];

            if(low<0){
                aux[0]++;
            }
            else if(low>=n){
               aux[n-1]++;
            }
            else{
                aux[low]++;
            }

            if(high<n-1 && high>=0){
                --aux[high+1];
            }

        }

        int val = 0;
        for(int i=0;i<n;i++){
            val += aux[i];
            rad[i] = val;
        }

        ll ans1=0;
        ll ans2=0;

        for(int i=0;i<n;i++){
            ans2 = ans2^rad[i];
            ans1 = ans1^h[i];
        }

        if(ans1==ans2){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;

    }
    return 0;
}
