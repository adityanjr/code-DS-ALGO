#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll a;

    while(cin>>a && a!=0){
         vector<ll>vec(a);
         for(int i=0;i<a;i++){
            cin>>vec[i];
         }
         ll max_area = LLONG_MIN;
         ll i = 0;
         stack<ll>ss;

         while(i<a){
            if(ss.empty() || vec[ss.top()]<=vec[i]){
                    ss.push(i++);
             }
                else{

                    while(!ss.empty() && vec[ss.top()]>vec[i] ){
                        ll top  = ss.top();
                        ss.pop();
                        ll area = vec[top]*(ss.empty()?i:i-ss.top()-1);
                        max_area = max(max_area,area);
                    }
                    ss.push(i);
                    i++;
                }
         }
         while(!ss.empty()){
            ll top = ss.top();
            ss.pop();
            ll area = vec[top]*(ss.empty()?i:(i-ss.top()-1));
            max_area = max(max_area,area);
         }
         cout<<max_area<<endl;
    }
    return 0;
}
