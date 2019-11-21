#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    size_t numPlates = 0, usedPlates = 0;
    unsigned long long minMeatballs = 0, numMeatballs =0, total = 0;

    int numCases; scanf("%d\n",&numCases);
    while(numCases--){
        scanf("%zd %llu\n", &numPlates, &minMeatballs);
        unsigned long long *numMeatballs = new unsigned long long[numPlates]; 
        for(size_t k = 0; k < numPlates; k++){scanf("%llu",numMeatballs+k);}
        sort(numMeatballs, numMeatballs + numPlates);

        usedPlates = 0; total = 0;
        for(int k = numPlates - 1; k >= 0; k--){
            total += numMeatballs[k];
            usedPlates++;
            if(total >= minMeatballs){break;}
        }
        if(total >= minMeatballs){printf("%zd\n",usedPlates);}
        else{printf("-1\n");}
    }

    return 0;
}
