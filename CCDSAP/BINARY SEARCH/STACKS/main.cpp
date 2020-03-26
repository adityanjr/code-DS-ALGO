#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>stk;
        stk.push_back(arr[0]);
        for(int i=1;i<n;i++){
            auto itr  =  upper_bound(stk.begin(),stk.end(),arr[i]);
            if(itr == stk.end()){
                stk.push_back(arr[i]);
            }
            else{
                *itr = arr[i];
            }
        }
        cout<<stk.size()<<" ";
        for(int i=0;i<stk.size();i++){
            cout<<stk[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
