#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)

ll cost[200020]={0};

int main() {
    ll n;
    cin>>n;
    vector<int>one;
    vector<int>One;
    vector<int>Two;
    vector<int>two;

    ll total_weight = 0;

    while(n--){
        int w,c;
        cin>>w>>c;
        total_weight += w;
        if(w&1) One.pb(c);
        else Two.pb(c);
    }

    sort(One.begin(),One.end());
    sort(Two.begin(),Two.end());

    one = One;
    two = Two;

    ll res = 0;
    for(int i=2;i<=total_weight;i+=2){
            ll max1 = 0;
            ll max2 = 0;

            if(two.size()>0){
                max1 +=  two[two.size()-1];
            }

            if(one.size()>1){
                max2  += one[one.size()-1] + one[one.size()-2];
            }
            else if(one.size()>0)
            {
                max2 += one[one.size()-1];
            }

            if(max1>=max2){
                res += max1;
                two.pop_back();
            }
            else
            {   res += max2;
                one.pop_back();
                if(one.size()>0)
                  one.pop_back();
            }
            cost[i] = res;
      }

      if(One.size()>0){
        cost[1] = One[One.size()-1];
        One.pop_back();
      }
      res = cost[1];

     for(int i=3;i<=total_weight;i+=2){
            ll max1 = 0;
            ll max2 = 0;

            if(Two.size()>0){
                max1 +=  Two[Two.size()-1];
            }

            if(One.size()>1){
                max2  += One[One.size()-1] + One[One.size()-2];
            }
            else if(One.size()>0)
            {
                max2 += One[One.size()-1];
            }

            if(max1>=max2){
                res += max1;
                Two.pop_back();
            }
            else
            {   res += max2;
                One.pop_back();
                if(One.size()>0)
                  One.pop_back();
            }
            cost[i] = res;
        }

    for(int i=1;i<=total_weight;i++)
           cout<<cost[i]<<" ";
}
