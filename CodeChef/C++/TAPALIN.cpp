#include <cstdio>
using namespace std;

const int alphabetSize = 26;
const long MOD = 1000000007;


unsigned long long powerMod(unsigned long long base, unsigned long long exponent){
    unsigned long long output = 1;
    while(exponent > 0){
        if(exponent % 2){output = (output * base) % MOD;}
        if(exponent /= 2){base = (base * base) % MOD;}
    }
    return output;
}


unsigned long long expSum(int n){
    unsigned long long inverse = powerMod(alphabetSize - 1,MOD - 2);  //Fermat's little theorem
    unsigned long long p = (n + 1)/2;
    unsigned long long firstTerm = powerMod(alphabetSize,p);
    unsigned long long output = 2 * alphabetSize* (firstTerm -1) % MOD; output = output * inverse % MOD;
    if(n%2){output = (MOD + output - firstTerm) % MOD;}  //Subtract 26^k for odd n;CAREFUL TO NOT MAKE FIRST TERM NEGATIVE AS IT IS unsigned long long;
    return output;
}


int main(){

    int numCases; scanf("%d\n",&numCases);
    while(numCases--){
        unsigned long long numLetters; scanf("%llu\n",&numLetters);
        unsigned long long output = expSum(numLetters);
        printf("%llu\n",output);
    }
    return 0;
}
