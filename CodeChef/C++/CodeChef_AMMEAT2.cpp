#include <iostream>
using namespace std;

int main(){

    int numCases; scanf("%d\n",&numCases);

    int upperLimit = 0, numPlates = 0;
    while(numCases--){
        scanf("%d %d\n", &upperLimit, &numPlates);
        if(upperLimit == 1 && numPlates == 1){printf("1");}
        else if(numPlates > upperLimit / 2){printf("-1");}
        else{for(int k = 1; k <= numPlates; k++){printf("%d ",2 * k);}}
        printf("\n");
    }
    return 0;
}
