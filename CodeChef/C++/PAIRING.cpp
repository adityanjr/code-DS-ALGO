#include <iostream>
#include <vector>
using namespace std;

int main(){

    int numCases; scanf("%d\n",&numCases);

    int numChefs = 0, numPairs = 0, firstChef = 0, secondChef = 0;
    while(numCases--){
        scanf("%d %d\n", &numChefs, &numPairs);
        bool *usedChefs = new bool[numChefs]; 
        bool *usedPairs = new bool[numPairs];
        vector< pair<int,int> > chefPairs(numPairs,pair<int,int>(0,0));

        for(int k = 0; k < numChefs; k++){usedChefs[k] = 0;}
        for(int k = 0; k < numPairs; k++){
            usedPairs[k] = 0;
            scanf("%d %d\n", &firstChef, &secondChef);
            chefPairs[k] = pair<int,int>(firstChef,secondChef);
        }

        for(int k = numPairs - 1; k >= 0 ; k--){
            firstChef  = chefPairs[k].first; secondChef = chefPairs[k].second; 
            if(usedChefs[firstChef] || usedChefs[secondChef]){continue;}
            usedChefs[firstChef] = 1; usedChefs[secondChef] = 1; usedPairs[k] = 1;
        }

        for(int k = 0; k < numPairs ; k++){if(usedPairs[k]){printf("%d ", k);}}
        printf("\n");
    }
    return 0;
}
