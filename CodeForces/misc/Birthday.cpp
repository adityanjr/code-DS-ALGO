#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,k,l,ans,x;
    double y;
    scanf("%lld %lld %lld %lld",&n,&m,&k,&l);
    if(n<m)
        printf("-1\n");
    else
    {
    //diff coins that they can gift him
    x=n-k;
    if(x<l)
        printf("-1\n");//because if there doesnt exist
        //l different coins how they can gift them
    else
    {

        y=(double)(l+k)/m-(l+k)/m;
        if(y==0)
            ans=(l+k)/m;   //because ceil is not working properly here ceil((double)a/b) giving wrong ans
        else
            ans=(l+k)/m+1;
        if(ans*m<=n)
        printf("%lld\n",ans);
        else
            printf("-1\n");
    }
    }
}
