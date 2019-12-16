#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    return(b.second>a.second);
}

#define ll long long int
int main() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>>vec;
    for(ll i=0;i<n;i++){
       ll a;
       ll b;
       cin>>a>>b;
       vec.push_back({a,b});
    }

   sort(vec.begin(),vec.end());

    for(int i=0;i<n;i++){
       int a = vec[i].first;
       int b = vec[i].second;
       ll f = a - b;
       ll s = a + b;
       vec[i]={f,s};
    }

       sort(vec.begin(),vec.end(),cmp);

    int val =  vec[0].second;
    int ans = 1;
    for(ll i=1;i<n;i++){
        if(vec[i].first>=val){
            ans++;
           val = vec[i].second;
        }
    }
    cout<<n-ans<<endl;
	return 0;
}
