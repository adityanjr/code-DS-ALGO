#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int w,h,n;
        cin>>w>>h>>n;
        vector<int>wid;
        vector<int>height;
        vector<int>wid1;
        vector<int>height1;
        if(n==0){
            cout<<w*h<<endl;
            continue;
        }

        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            wid.push_back(a);
            height.push_back(b);
        }

        sort(height.begin(),height.end());
        sort(wid.begin(),wid.end());

        wid1.push_back(wid[0]-1);
        for(int i=1;i<n;i++){
            wid1.push_back(wid[i] - wid[i-1]-1);
        }
        wid1.push_back(w-wid[n-1]);

        height1.push_back(height[0]-1);
        for(int i=1;i<n;i++){
           height1.push_back(height[i] - height[i-1]-1);
        }
        height1.push_back(h-height[n-1]);

        sort(height1.begin(),height1.end());
        sort(wid1.begin(),wid1.end());

        cout<<wid1[n]*height1[n]<<endl;
    }
    return 0;
}
