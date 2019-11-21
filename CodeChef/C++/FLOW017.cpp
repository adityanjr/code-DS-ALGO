#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long a, b, c; scanf("%ld %ld %ld\n", &a, &b, &c);
        long res(0);
        if(a <= b && b <= c){res = b;}
        else if(a <= c && c <= b){res = c;}
        else if(b <= a && a <= c){res = a;}
        else if(b <= c && c <= a){res = c;}
        else if(c <= a && a <= b){res = a;}
        else if(c <= b && b <= a){res = b;}

        printf("%ld\n", res);
    }

    return 0;
}
