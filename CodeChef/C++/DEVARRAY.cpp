#include <cstdio>

int main(){

    long n, q; scanf("%ld %ld\n", &n, &q);
    long min(1000000000), max(0);
    while(n--){
        long x; scanf("%ld", &x);
        min = (x < min) ? x : min;
        max = (x > max) ? x : max;
    }

    while(q--){
        long t; scanf("%ld\n", &t);
        puts((min <= t && t <= max) ? "Yes" : "No");
    }

    return 0;
}
