#include <iostream>
using namespace std;

int main(){

    size_t t; scanf("%zd",&t);
    int *counts = new int[10];
    int min, candle;
    while(t--){

        min = 9;
        for(int k = 0; k <= 9 ; k++){scanf("%d",(counts+k));}
        for(int k = 0; k <= 9 ; k++){
            if( counts[k] < min ){
                min = counts[k];
                candle = k;
            }
        }

        if( candle == 0 ) {printf("1");}
        for(int k = 0 ; k <= min ; k++){printf("%d",candle);}
        printf("\n");
    }

    return 0;
}
