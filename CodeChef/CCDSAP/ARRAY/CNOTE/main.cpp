#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int x,y,k,n;
    while(t--){
        cin>>x>>y>>k>>n;
        int chefwants = x-y;
        bool ans = false;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            if((a>=chefwants && b<=k))
                ans = true;
        }
        if(ans)
            cout<<"LuckyChef"<<endl;
        else
            cout<<"UnluckyChef"<<endl;
    }
    return 0;
}
