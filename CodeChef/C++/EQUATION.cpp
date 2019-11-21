#include <iostream>
using namespace std;

long long Nc3(long long n){
    if(n < 0){return 0;}
    return (n+1)*(n+2)*(n+3)/6;
}


int main(){

    int numCases; scanf("%d\n",&numCases);
    long long A = 0, B = 0, C = 0, N = 0, output = 0;
    while(numCases--){
        scanf("%lld %lld %lld %lld\n", &N, &A, &B, &C);
        output =   Nc3(N) - Nc3(N-A-1) - Nc3(N-B-1) - Nc3(N-C-1) + Nc3(N-A-B-2) + Nc3(N-B-C-2) + Nc3(N-A-C-2) - Nc3(N-A-B-C-3);
        printf("%lld\n",output);
    }
    return 0;
}
