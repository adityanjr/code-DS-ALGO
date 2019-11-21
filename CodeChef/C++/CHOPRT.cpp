#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long x, y; scanf("%ld %ld\n", &x, &y);
        if(x < y){puts("<");}
        else if(x > y){puts(">");}
        else if(x == y){puts("=");}
    }

    return 0;
}
