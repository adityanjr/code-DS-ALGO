#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long long n, m; scanf("%lld %lld\n", &n, &m);
        puts( ((m % 2) && (n % 2)) ? "No" : "Yes");
    }

    return 0;
}
