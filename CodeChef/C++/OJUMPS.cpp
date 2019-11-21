#include <cstdio>

int main(){

    long long a; scanf("%lld\n", &a);
    puts(((a % 6 == 0) || (a % 6 == 1) || (a % 6 == 3)) ? "yes" : "no");

    return 0;
}
