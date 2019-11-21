#include <cstdio>

int main(){
    
    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        long a(0);
        while(n--){long x; scanf("%ld\n", &x); a ^= x;}
        printf("%ld\n", a);
    }

    return 0;
}
