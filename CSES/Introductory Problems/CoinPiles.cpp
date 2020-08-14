// Remove (2 and 1) coins from two piles of coins in any order.
// Find if possible to empty the two piles of coins.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--)
    {
        ll a, b;
        cin >> a >> b;
        if((a + b) % 3 == 0 && 2 * a >= b && b * 2 >= a)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
