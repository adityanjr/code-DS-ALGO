#include <cstdio>

long gcd(long a, long b){return (a == 0) ? b : gcd(b % a, a);}

int main(){

    int T; scanf("%d\n", &T);
    while(T--){

        long x, y; scanf("%ld %ld\n", &x, &y);
        printf("%ld %ld\n", gcd(x, y), (x * y / gcd(x, y)));
    }

    return 0;
}
