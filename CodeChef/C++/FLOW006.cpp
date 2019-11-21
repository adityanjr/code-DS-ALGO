#include <cstdio>

int sumOfDigits(long x){
    int res(0);
    while(x > 0){res += (x % 10); x /= 10;}
    return res;
}


int main(){

    int T; scanf("%d\n", &T);
    while(T--){
        long num; scanf("%ld\n", &num);
        printf("%d\n", sumOfDigits(num));
    }

    return 0;
}
