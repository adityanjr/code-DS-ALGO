#include <cstdio>

long gcd (long a, long b){return (b == 0) ? a : gcd (b, a%b);}

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long m, n; scanf("%ld %ld\n", &n, &m);
        printf("%ld\n", m * n / (gcd(m, n) * gcd(m, n)));
    }

    return 0;
}
