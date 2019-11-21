#include <cstdio>
#include <vector>


int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::vector<long> a(n);
        for(int p = 0; p < n; p++){scanf("%ld", &a[p]);}
        std::vector<long> b(n);
        for(int p = 0; p < n; p++){scanf("%ld", &b[p]);}

        long count(b[0] <= a[0]);
        for(int p = 1; p < n; p++){count += (b[p] <= a[p] - a[p - 1]);}
        printf("%ld\n", count);
    }

    return 0;
}
