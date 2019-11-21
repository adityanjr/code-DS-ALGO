#include <cstdio>

bool isPrime(long x){
    for(long p = 2; p * p <= x; p++){if(x % p == 0){return false;}}
    return true;
}


int main(){

    int T; scanf("%d\n", &T);
    while(T--){
        long n; scanf("%ld\n", &n);
        puts(isPrime(n) ? "yes" : "no");
    }

    return 0;
}
