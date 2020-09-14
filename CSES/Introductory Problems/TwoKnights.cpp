// Number of ways such that two knights don't attack each other on nXn board
#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        ll t = i * i;// Size of the chess board 
        t = (t * (t - 1)) / 2; // Number of ways to choose two pos
        if(i > 2)
        {
            t -= 4 * (i - 1) * (i - 2); // Number of 2X3 and 3X2 submatrices
        }
        cout << t << "\n";
    }
    return 0;
}
