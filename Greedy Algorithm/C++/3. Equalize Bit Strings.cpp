// ### EqualizeBitStrings

// You are given two binary strings *a* and *b* of the same length. You can perform the following two operations on the string *a*:

// - Swap any two bits at indices *i* and *j* respectively (1 ≤ *i*, *j* ≤ *n*), the cost of this operation is |*i−j*|, 
// that is, the absolute difference between *i* and *j*.
// - Select any arbitrary index *i* (1 ≤ *i* ≤ *n*) and flip (change 0 to 1 or 1 to 0) the bit at this index. The cost of this operation is 1.

// Find the minimum cost to make the string *a* equal to *b*. It is not allowed to modify string *b*.



#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(50);
    string a, b;
    lli n, i, x=0;
    cin>>n>>a>>b;
    for(i=0;i<n-1;i++){
        if(a[i]!=b[i]){
            if(a[i+1]!=b[i+1] && a[i]!=a[i+1]){
                a[i]=b[i];
                a[i+1]=b[i+1];
                x++;
                i++;
            }
            else{
                a[i]=b[i];
                x++;
            }
        }
    }
    if(a[n-1]!=b[n-1]){
        x++;
    }
    cout<<x<<endl;
}
