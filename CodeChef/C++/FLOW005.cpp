#include <cstdio>
#include <vector>

int main(){

    std::vector<long> v(6); 
    v[0] = 100; v[1] = 50; v[2] = 10; v[3] = 5; v[4] = 2; v[5] = 1;

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        long count(0);
        for(int p = 0; p < v.size(); p++){count += n / v[p]; n %= v[p];}
        printf("%ld\n", count);
    }

    return 0;
}
