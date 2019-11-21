#include <iostream>
using namespace std;

inline size_t gcd (size_t a, size_t b){return (b == 0) ? a : gcd (b, a%b);}

int main(){

    size_t length, temp = 0, output = 0;
    int numCases; scanf("%d\n",&numCases);
    while(numCases--){
        scanf("%zd\n", &length);
        output = 0;
        for(size_t k = 0; k < length; k++){
            scanf("%zd", &temp);
            output = gcd(output, temp);
        }
        printf("%zd\n",output);
    }
    return 0;
}
