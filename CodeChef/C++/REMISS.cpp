#include <cstdio>

int main(){

    int t; scanf("%d", &t);
    while(t--){
        long A, B; scanf("%ld %ld\n", &A, &B);
        printf("%ld %ld\n", ((A > B) ? A : B), A + B);
    }

    return 0;
}
