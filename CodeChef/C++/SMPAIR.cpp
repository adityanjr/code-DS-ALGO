#include <cstdio>

int main(){

    long T; scanf("%ld\n", &T);
    while(T--){

        long N; scanf("%ld\n", &N);
        long smallestA(0), smallestB(0);
        for(long p = 0; p < N; p++){
            long x; scanf("%ld\n", &x);
            if(smallestA == 0 || x < smallestA){smallestB = smallestA; smallestA = x;}
            else if(smallestB == 0 || x < smallestB){smallestB = x;}
        }

        printf("%ld\n", smallestA + smallestB);
    }

    return 0;
}
