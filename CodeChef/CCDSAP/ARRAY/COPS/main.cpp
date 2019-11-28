#include <bits/stdc++.h>
using namespace std;

int main()
{   int t;

    cin>>t;
    while(t--){
        int x,y,M;
        cin>>M>>x>>y;
        int arr[10];
        vector<pair<int,int>>vec;
        int val =  x*y;
        for(int i=0;i<M;i++){
            cin>>arr[i];
            vec.push_back(make_pair(arr[i]-val,arr[i]+val));
        }
        sort(arr,arr+M);

        int ar[101]={false};

        for(auto x: vec){
            for(int i=1;i<=100;i++){
                if((i>=x.first) && (i<=x.second)){
                    ar[i]=true;
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=100;i++) if(!ar[i]) ans++;
        cout<<ans<<endl;
    }
    return 0;
}


