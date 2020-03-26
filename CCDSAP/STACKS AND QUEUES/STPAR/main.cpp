#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    while(cin>>n && n!=0){
        stack<int>ss;
        vector<int>arr(n);

        for(int i=0;i<n;i++) cin>>arr[i];

        vector<int>vec;
        vector<int>vec1 = arr;
        sort(vec1.begin(),vec1.end());

        ss.push(arr[0]);

        for(int i=1;i<n;i++){
            if(arr[i]>ss.top()){
                while( !ss.empty() && arr[i]>ss.top()){
                vec.push_back(ss.top());
                ss.pop();
                }
                ss.push(arr[i]);
            }
            else{
                ss.push(arr[i]);
            }
        }

       if(!ss.empty()){
             while(!ss.empty()){
                vec.push_back(ss.top());
                ss.pop();
             }
        }
        bool flag = true;

        // for(int i=0;i<n;i++) cout<<vec[i]<<" ";

        for(int i=0;i<n;i++){
            if(vec1[i]!=vec[i]){
                flag = false;
                break;
            }
        }

        if(flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
