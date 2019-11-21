#include <cstdio>
#include <vector>

bool isPalindrome(long x){
    std::vector<int> digits;
    while(x > 0){digits.push_back(x % 10); x /= 10;}
    int n = digits.size();
    for(int p = 0; p < n; p++){if(digits[p] != digits[n - 1 - p]){return false;}}
    return true;
}

int main(){

    //Precompute
    const long L(1), R(100000);
    std::vector<long long> sumVec(R + 1, 0);
    for(long p = 1; p <= R; p++){sumVec[p] = sumVec[p - 1] + p * isPalindrome(p);}

    int t; scanf("%d\n", &t);
    while(t--){
        long l, r; scanf("%ld %ld\n", &l, &r);
        printf("%lld\n", sumVec[r] - sumVec[l - 1]);
    }

    return 0;
}
