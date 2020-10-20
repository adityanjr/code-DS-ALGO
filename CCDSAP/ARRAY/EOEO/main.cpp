//Problem link : https://www.codechef.com/problems/EOEO


#include<bits/stdc++.h>
#define ll long long
#define SPEEDHACK ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
    
    SPEEDHACK
    ll t,c=0;
    cin>>t;
    while(t--)
    {
        ll ts;
        cin>>ts;
        if(ts%2==1)
        {
            cout<<ts/2<<'\n';
        }
        else if(ts && (!(ts&(ts-1))))
        {
            cout<<0<<'\n';
        }
        else
        {
            while(ts%2==0)
            {
                ts/=2;
            }
            cout<<ts/2<<'\n';
        }
    }
    return 0;
}

//End of Program