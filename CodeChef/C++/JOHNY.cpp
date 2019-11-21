#include <cstdio>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        int n; scanf("%d\n", &n);
        std::vector<long> a(n, 0);
        for(int p = 0; p < n; p++){scanf("%ld ", &a[p]);}
        int k; scanf("%d\n", &k);
        long x = a[k - 1];
        int count(0);
        for(int p = 0; p < n; p++){count += (a[p] <= x);}
        printf("%d\n", count);
    }

    return 0;
}
