#include <cstdio>

int main(){

    int T; scanf("%d\n", &T);
    while(T--){
        long x, y; scanf("%ld %ld\n", &x, &y);
        printf("%ld\n", x % y);
    }

    return 0;
}
