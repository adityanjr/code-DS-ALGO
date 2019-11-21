#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(long n){
    n = abs(n);

    size_t order = 1, msb = 1, lsb = 1;
    while(10 * order < n){order *= 10;}
    
    while(n > 0){
        msb = n / order; lsb = n % 10;
        if( msb != lsb){return 0;}
        n = n - order * msb; n /= 10; order /= 100;
    }
    return 1;
}

int main(int argc, char* argv[]){

    const long N = 2000000;
    bool *primes = new bool[N+1];
    primes[0] = 0; primes[1] = 0; for(size_t k = 2; k <= N; k++){primes[k] = 1;}
    
    for(size_t k = 2; k <= sqrt(N) ; k++){
        if(!primes[k]){continue;}
        for(size_t m = 2*k ; m <= N ; m+=k){primes[m] = 0;}
    }

    size_t lowerBound; cin >> lowerBound;
    for(size_t k = lowerBound; k < N ; k++){if(primes[k] && isPalindrome(k)){cout << k << endl; break; } }

    return 0;
}
