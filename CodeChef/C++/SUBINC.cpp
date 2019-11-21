#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long long n; scanf("%lld\n", &n);
        long long run(0), total(0), prev(-1);
        while(n--){
            long long x; scanf("%lld\n", &x);
            if((prev < 0) || (x < prev)){run = 1;}
            else{++run;}
            total += run;
            prev = x;
        }

        printf("%lld\n", total);
    }

    return 0;
}
