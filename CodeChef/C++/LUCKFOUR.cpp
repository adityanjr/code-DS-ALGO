#include <cstdio>

int main(){

    int T; scanf("%d\n", &T);
    while(T--){
        long x; scanf("%ld\n", &x);
        int count(0);
        while(x > 0){count += (x % 10 == 4); x /= 10;}
        printf("%d\n", count);
    }

    return 0;
}
