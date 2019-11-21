#include <cstdio>

int getLSD(long x){return (x % 10);}
int getMSD(long x){while(x > 9){x /= 10;}; return x;}

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long a; scanf("%ld\n", &a);
        printf("%d\n", getLSD(a) + getMSD(a));
    }

    return 0;
}
