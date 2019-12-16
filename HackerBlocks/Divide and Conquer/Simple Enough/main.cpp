#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<bool>base={1,0,1};

vector<bool> solve(ll n){
    if(n==2)
        return base;

    vector<bool>temp = solve(floor(n/2));
    temp.push_back(n%2);
    temp.insert(temp.end(),temp.begin(),temp.end()-1);
    return temp;

}
int main()
{
    ll n;
    ll l;
    ll r;
    vector<bool>vec(1000000000000);
    cin>>n>>l>>r;
    vec = solve(n);
    ll occurences = 0;

    for(ll i=l-1;i<r;i++){
        if(vec[i]==1)
            occurences++;
    }
    cout<<occurences<<endl;

    return 0;
}
