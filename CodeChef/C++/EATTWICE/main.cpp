#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool compare(const pair<ll,ll>&i, const pair<ll,ll>&j){
    return i.second > j.second;
}


int main()
{
    ll t;
    ll n,m;
    cin>>t;
    vector<pair<int,int>>vec;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            ll d,v;
            cin>>d>>v;
            vec.push_back(make_pair(d,v));
        }
       sort(vec.begin(),vec.end(),compare);
           ll taste =0;
           taste = vec[0].second;
           ll temp = vec[0].first;

        for(int i=1;i<n;i++){
            if(temp!=vec[i].first){
                taste+=vec[i].second;
                break;
            }
        }

        cout<<taste<<endl;
        vec.clear();
    }
    return 0;
}
