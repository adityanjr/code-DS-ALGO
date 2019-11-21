#include <cstdio>

int main(){

    long long x(0);
    while(scanf("%lld\n", &x) != EOF){
        long long pow = 5;
        long long count(0);
        while(pow <= x){count += x / pow; pow *= 5;}
        printf("%lld\n", count);
    }

    return 0;
}
