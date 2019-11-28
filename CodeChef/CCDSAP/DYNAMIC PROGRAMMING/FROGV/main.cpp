#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int>&p, const pair<int,int>&p1){
    return p.first > p1.first;
}
int main()
{
    int n,k,p;
    cin>>n>>k>>p;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++){
        vec.push_back({arr[i],i});
    }
    sort(vec.begin(),vec.end(),compare);
    vector<int>MAXDIS(100001);

    MAXDIS[vec[0].second] = vec[0].first+k;
  //cout<<MAXDIS[vec[0].second]<<" ";
    for(int i=1;i<n;i++){
        if((vec[i-1].first-vec[i].first)>k){
            MAXDIS[vec[i].second] = vec[i].first + k;
        }
        else{
            MAXDIS[vec[i].second] = MAXDIS[vec[i-1].second];
        }
       // cout<<MAXDIS[vec[i].second]<<" ";
    }
    // cout<<endl;
    for(int i=0;i<p;i++){
        int a,b;
        cin>>a>>b;
        if(MAXDIS[a-1]==MAXDIS[b-1])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
