#include <cstdio>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::vector<long> rowvec(n * n + 1, 0);
        std::vector<long> colvec(n * n + 1, 0);
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                long a; scanf("%ld", &a);
                rowvec[a] = row; colvec[a] = col;
            }
        }

        long long total(0);
        for(int p = 2; p <= n * n; p++){
            long drow = rowvec[p] - rowvec[p - 1]; if(drow < 0){drow = -drow;}
            long dcol = colvec[p] - colvec[p - 1]; if(dcol < 0){dcol = -dcol;}
            total += (drow + dcol);
        }

        printf("%lld\n", total);
    }

    return 0;
}
