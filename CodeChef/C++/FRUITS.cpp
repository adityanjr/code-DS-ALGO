#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        int n, m, k; scanf("%d %d %d\n", &n, &m, &k);
        int diff = n - m; if(diff < 0){diff = -diff;}
        diff = (diff < k) ? 0 : (diff - k);
        printf("%d\n", diff);
    }

    return 0;
}
