#include <iostream>
using namespace std;

int countBinaryOnes(int x){
    int output = 0;
    while(x > 0){output += x%2;x /= 2;}
    return output;
}

int main(){

    int t; scanf("%d",&t);
    int x, y, N, a, b, c, output;

    while(t--){
        scanf("%d %d %d", &N, &x, &y);
        a = countBinaryOnes(x);
        b = countBinaryOnes(y);
        c = (a + b < N) ? (a+b):(2*N -(a + b));

        output = 0;
        for(int k = 0; k < N ; k++){output = 2 * output + (k < c);}
        printf("%d\n",output);
    }

    return 0;
}
