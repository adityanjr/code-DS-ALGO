#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long b; scanf("%ld\n", &b);
        long u = (b - 2) / 2;
        printf("%ld\n", u * (u + 1) / 2);

    }

    return 0;
}
