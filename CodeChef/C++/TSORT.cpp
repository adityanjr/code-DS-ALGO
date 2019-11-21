#include <cstdio>
#include <vector>
#include <algorithm>

int main(){

    long t; scanf("%ld\n", &t);
    std::vector<long> a(t);
    for(long p = 0; p < t; p++){scanf("%ld\n", &a[p]);}
    sort(a.begin(), a.end());
    for(long p = 0; p < t; p++){printf("%ld\n", a[p]);}; 

    return 0;
}
