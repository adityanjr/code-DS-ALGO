#include <iostream>
using namespace std;

int main(){
    size_t A,N,K;
    scanf("%zd %zd %zd", &A, &N, &K);

    for(size_t comp = 0 ; comp < K ; comp++){
        printf("%zd ",A%(N+1));
        A /= (N+1);
    }
    return 0;
}
