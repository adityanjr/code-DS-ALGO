#include <cstdio>
#include <vector>

int main(){

    const long MOD = 1000000007;
    long n, k; scanf("%ld %ld\n", &n, &k);
    std::vector<long> a(n, 0);
    for(int p = 0; p < n; p++){scanf("%ld", &a[p]);}

    std::vector<long> dp(n, MOD);
    dp[0] = a[0];
    for(int p = 0; p < n; p++){
        for(int s = 1; s <= k; s++){
            if(p + s >= n){break;}
            long candidate = (dp[p] * a[p + s]) % MOD;
            dp[p + s] = (candidate < dp[p + s]) ? candidate : dp[p + s];
        }
    }

    printf("%ld\n", dp[n - 1]);

    return 0;
}
