#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll Mov[20001];
ll Sat[20001];
// Gives TLE, i could not understand editorial.
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll k, q;
        cin>>k>>q;
        for(int i=0;i<k;i++) cin>>Mov[i];
        for(int i=0;i<k;i++) cin>>Sat[i];

        vector<ll>arr;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                arr.push_back(Mov[i] + Sat[j]);
            }
        }
        sort(arr.begin(),arr.end());
        while(q--){
            ll ques;
            cin>>ques;
            cout<<arr[ques-1]<<"\n";
        }
    }
    return 0;
}
