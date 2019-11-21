#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n, k; scanf("%ld %ld\n", &n, &k);
        long max(0);
        for(int p = 1; p <= k; p++){
            if(max < (n % p)){max = n % p;}
        }

        printf("%ld\n", max);
    }

    return 0;
}
