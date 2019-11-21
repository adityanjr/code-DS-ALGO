#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long long n, k; scanf("%lld %lld\n", &n, &k);
        printf("%lld %lld\n", n / k, n % k);
    }

    return 0;
}
