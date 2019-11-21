#include <cstdio>

int main(){

    const long B = 1500;
    int t; scanf("%d\n", &t);
    while(t--){
        long base; scanf("%ld\n", &base);
        double total(0);
        if(base < B){total = 2 * base;}
        else{total = 500 + 1.98 * base;}
        printf("%g\n", total);
    }

    return 0;
}
