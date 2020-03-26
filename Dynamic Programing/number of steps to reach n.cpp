#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(x) cout <<#x<<": "<<x<<'\n';

const int N = 100005;

int ans = 0, n;

void fun(int pos) {
    db(pos);
    if (pos > n) return;
    if (pos == n) {
        ans++;
        return ;
    }
    fun(pos + 1);
    fun(pos + 2);
    fun(pos + 3);
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        cin >> n;
        fun(0);
        cout << ans;
    }
}