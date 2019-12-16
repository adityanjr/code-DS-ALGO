#include <iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<queue>
using namespace std;

int main()
{
        int w=INT_MIN,h=INT_MIN,n;
        cin>>n;
        vector<int>wid;
        vector<int>height;
        priority_queue<int>wid1;
        priority_queue<int>height1;

        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            w = max(w,a);
            h = max(h,b);
            wid.push_back(a);
            height.push_back(b);
        }

        sort(height.begin(),height.end());
        sort(wid.begin(),wid.end());

        wid1.push(wid[0]-1);
        height1.push(height[0]-1);
        for(int i=1;i<n;i++){
            wid1.push(wid[i] - wid[i-1]-1);
            height1.push(height[i] - height[i-1]-1);
        }
        cout<<height1.top()*wid1.top()<<endl;
    return 0;
}
