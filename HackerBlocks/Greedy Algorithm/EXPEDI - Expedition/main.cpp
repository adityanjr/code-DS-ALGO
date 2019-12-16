#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
#define ll long long int

struct compare{
    bool operator()(pair<int,int>l, pair<int,int>r){
    return l.first < r.first;
    }
}cmp;

int main()
{
     ll t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>>v;
        priority_queue<int>pq;

        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            v.push_back({a,b});
        }

        int d,f;
        cin>>d>>f;

        for(int i=0;i<n;i++){
            v[i].first = d - v[i].first;
        }

        sort(v.begin(),v.end(),cmp);

        int x = 0;
        int prev = 0;
        int ans = 0;
        bool flag = false;
        while(x<n){
            if((v[x].first - prev)<=f){
                f -= (v[x].first-prev);
                prev = v[x].first;
                pq.push(v[x].second);
                x++;
            }
            else{
                if(pq.empty()){
                    flag = true;
                    break;
                }

                f+=pq.top();
                ans++;
                pq.pop();
            }

        }

        if(flag){
            cout<<"-1"<<endl;
            continue;
        }

        d = d-v[n-1].first;

        if(d<=f){
            cout<<ans<<endl;
            continue;
        }

        while(d>f){
            if(pq.empty()){
                flag = true;
                break;
            }
            else{
                f += pq.top();
                pq.pop();
                ans++;
            }
        }
        if(flag){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ans<<endl;
     }
    return 0;
}
