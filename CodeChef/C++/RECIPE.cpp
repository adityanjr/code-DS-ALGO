#include <iostream>
using namespace std;

int gcd (int a, int b){return (b == 0) ? a : gcd (b, a%b);}

int main(){
    int t; scanf("%d",&t);
    int number, divisor;

    while(t--){
        scanf("%d",&number);
        int *quantities = new int[number];

        scanf("%d",quantities);
        divisor = quantities[0];
        for(int k = 1; k < number ; k++){
            scanf("%d",(quantities+k));
            divisor = gcd(divisor, quantities[k]);
        }
        for(int k = 0; k < number ; k++){printf("%d ",quantities[k]/divisor);}
        printf("\n");
    }

    return 0;
}
