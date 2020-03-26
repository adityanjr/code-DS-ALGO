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

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m;
        string s, t;
        cin >> s >> t;
        n = s.size();
        m = t.size();
        int lcs[n + 1][m + 1] = {};
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                }
                else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }
        // for(i=0;i<=n;i++){
        //     for(j=0;j<=m;j++){
        //         cout<<lcs[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        i = n; j = m;
        string ans;
        while (i > 0 && j > 0) {
            if (s[i - 1] == t[j - 1]) {
                ans += s[i - 1];
                i--; j--;
            }
            else {
                if (lcs[i - 1][j] > lcs[i][j - 1]) {
                    i--;
                }
                else {
                    j--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
}