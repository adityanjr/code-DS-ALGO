#include <cstdio>

int main(){

    int T; scanf("%d\n", &T);
    while(T--){
        int a, b, c; scanf("%d %d %d\n", &a, &b, &c);
        puts((a > 0 && b > 0 && c > 0 && a + b + c == 180) ? "YES" : "NO");
    }

    return 0;
}
