#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct compare{
    bool operator()(pair<int,int>l, pair<int,int>r){
    return l.second < r.second;
    }
}cmp;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            vec[i]  = {a,b};
        }
        sort(vec.begin(),vec.end(),cmp);
        int ans = 1;
        int val = vec[0].second;
        for(int i=1;i<n;i++){
             if(vec[i].first>=val){
                ans++;
                val = vec[i].second;
             }
        }
        cout<<ans<<endl;
    }
    return 0;
}
