// ### Maximum Increasing Subarray

// You are given array consisting of *n* integers. 
// Your task is to find the maximum length of an increasing subarray of the given array.

// A subarray is the sequence of consecutive elements of the array. 
// Subarray is called increasing if each element of this subarray strictly greater than previous.

#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(50);
    lli n;
    cin >> n;
    lli a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    lli ans = 1;
    lli out = 1;
    for(int i = 1; i<n; i++)
    {
        if(a[i] > a[i-1])
        {
            ans++;
        }
        else
        {
            ans = 1;
        }
        out = max(out,ans);
    }
    cout << out << endl;
}
