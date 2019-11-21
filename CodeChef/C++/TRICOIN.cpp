#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        long r(0), sum(0);
        for(int p = 1; p <= n; p++){
            sum += p;
            if(sum > n){break;}
            r = p;
        }
        printf("%ld\n", r);
    }

    return 0;
}
