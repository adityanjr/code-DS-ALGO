#include <cstdio>
#include <vector>

int main(){

    const long long MOD = 1000000007;
    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::vector<long> a(n + 1);
        for(int p = 0; p <= n; p++){scanf("%ld", &a[p]);}

        long long cp = 2;
        std::vector<long> w(n + 1);
        w[0] = cp; 
        for(int p = 1; p <= n; p++){w[p] = cp; cp *= 2; cp %= MOD;}

        long long res = 2 * a[0] * a[1];
        for(int p = 2; p <= n; p++){
            long long sum(0);
            for(int q = 0; q < p; q++){sum += (a[q] * w[q]) % MOD;}
            res = 2 * res + a[p] * sum;
            res %= MOD;
        }

        printf("%lld\n", res);
    }

    return 0;
}
