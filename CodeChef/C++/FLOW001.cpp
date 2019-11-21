#include <cstdio>

int main(){

    int T; scanf("%d\n", &T);
    while(T--){
        long a, b; scanf("%ld %ld\n", &a, &b);
        printf("%ld\n", a + b);
    }

    return 0;
}
