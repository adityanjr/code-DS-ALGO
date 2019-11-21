#include <cstdio>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        int n; scanf("%d\n", &n);
        std::vector<long> l(n, 0);
        for(int p = 0; p < n; p++){scanf("%ld", &l[p]);}
        std::vector<long> r(n, 0);
        for(int p = 0; p < n; p++){scanf("%ld", &r[p]);}

        long prodMax(0), rmax(0), pick(0);
        for(int p = 0; p < n; p++){
            if((l[p] * r[p] > prodMax) || (l[p] * r[p] == prodMax && r[p] > rmax)){
                prodMax = l[p] * r[p]; rmax = r[p]; pick = p + 1;
            }
        }

        printf("%ld\n", pick);
    }

    return 0;
}
