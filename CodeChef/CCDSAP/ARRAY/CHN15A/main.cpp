#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        long long int ans = 0;
        for(int i=0;i<n;i++){
            int v;
            cin>>v;
            if((v+k)%7==0){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
