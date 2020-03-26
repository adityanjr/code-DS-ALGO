#include <iostream>

using namespace std;

int main()
{
    long int n,t,a[100000],odd=0,even=0,res=0;
    cin>>t;
    for(int k=0;k<t;k++)
    {
    cin>>n;

    while(n>=1)
    {
        a[res]=n%10;
        res++;
        n/=10;
    }
    for(int i=0;i<res;i++)
    {
        if(a[i]%2!=0)
        {
            odd+=a[i];
        }
        else
            even+=a[i];
    }
    if(odd%3==0 || even%4==0)
    {
        cout<<"Yes";
    }
    else
        cout<<"No";
        odd=0;
        even=0;
        res=0;
        cout<<endl;
    }
    return 0;
}
