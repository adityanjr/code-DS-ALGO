#include <cstdio>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        int n, m, k; scanf("%d %d %d\n", &n, &m, &k);
        std::vector<bool> ignored(n + 1, 0);
        std::vector<bool> tracked(n + 1, 0);
        for(int p = 0; p < m; p++){int x; scanf("%d", &x); ignored[x] = 1;}
        for(int p = 0; p < k; p++){int x; scanf("%d", &x); tracked[x] = 1;}

        int both(0);
        int neither(0);
        for(int p = 1; p <= n; p++){
            both += (ignored[p] && tracked[p]);
            neither += 1 - (ignored[p] || tracked[p]);
        }

        printf("%d %d\n", both, neither);
    }

    return 0;
}
