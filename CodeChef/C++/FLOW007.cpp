#include <cstdio>
#include <vector>

long numReverse(long x){

    if(x <= 0){return x;}
    std::vector<int> digits;
    while(x > 0){digits.push_back(x % 10); x /= 10;}
    long res(0);
    for(int p = 0; p < digits.size(); p++){res = 10 * res + digits[p];}
    return res;
}

int main(){

    int T; scanf("%d\n", &T);
    while(T--){
        long n; scanf("%ld\n", &n);
        printf("%ld\n", numReverse(n));
    }

    return 0;
}
