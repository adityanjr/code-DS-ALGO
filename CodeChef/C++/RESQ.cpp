#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int numCases; scanf("%d\n",&numCases);
    size_t cakes = 0, length = 0;

    while(numCases--){
        scanf("%zd",&cakes);
        length = sqrt(cakes);
        while( cakes != length * (cakes / length) ){length--;}
        printf("%zd\n", cakes/length - length );
    }
    return 0;
}
