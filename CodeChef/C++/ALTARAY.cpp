#include <cstdio>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::vector<int> a(n, 0);
        for(int p = 0; p < n; p++){
            long x; scanf("%ld", &x);
            if(x < 0){a[p] = -1;}
            else if(x > 0){a[p] = 1;}
        }

        std::vector<long> b(n, 1);
        for(int p = n - 2; p >= 0; p--){
            if(a[p] * a[p + 1] == -1){b[p] = 1 + b[p + 1];}
            else{b[p] = 1;}
        }

        for(int p = 0; p < n ; p++){printf("%ld ", b[p]);}
        puts("");
    }

    return 0;
}
