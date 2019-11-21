#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long m, n; scanf("%ld %ld\n", &m, &n);
        printf("%ld\n", 2 * m * n - m - n);
    }

    return 0;
}
