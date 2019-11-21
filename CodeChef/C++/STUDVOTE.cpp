#include <cstdio>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        int n, k; scanf("%d %d\n", &n, &k);
        std::vector<int> votes(n + 1, 0);
        std::vector<bool> qualified(n + 1, 1);
        for(int p = 1; p <= n; p++){
            int x; scanf("%d", &x); 
            ++votes[x];
            qualified[p] = (x != p);
        }
        int count(0);
        for(int p = 1; p <= n; p++){if(qualified[p] && votes[p] >= k){++count;}}
        printf("%d\n", count);
    }

    return 0;
}
