#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long long n; scanf("%lld\n", &n);
        long long min(1000000);
        for(long long p = 0; p < n; p++){
            long long a; scanf("%lld", &a);
            min = (a < min) ? a : min;
        }
        printf("%lld\n", (n - 1) * min);
    }

    return 0;
}
