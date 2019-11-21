#include<cstdio>

int main(){

    long long n; scanf("%ld\n", &n);
    long long s(0);
    for(long p = 0; p < n; p++){long long x; scanf("%lld", &x); s += x;}
    puts( (s == (n * (n + 1) / 2)) ? "YES" : "NO");

    return 0;
}
