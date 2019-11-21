#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        int n; scanf("%d\n", &n);
        puts((n < 10) ? "What an obedient servant you are!" : "-1");
    }

    return 0;
}
