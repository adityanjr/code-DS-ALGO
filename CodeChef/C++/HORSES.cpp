#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int numCases; scanf("%d\n",&numCases);
    int numHorses  = 0;
    size_t minDiff = 0;

    while(numCases--){
        scanf("%d\n", &numHorses);
        size_t *speeds = new size_t[numHorses];
        for(int k = 0; k < numHorses; k++){scanf("%zd",speeds + k);}
        sort(speeds, speeds + numHorses);

        minDiff = speeds[numHorses - 1];
        for(int k = 1; k < numHorses ; k++){
            if(speeds[k] - speeds[k-1] < minDiff){
                minDiff = speeds[k] - speeds[k-1];
                if(minDiff == 0){break;}
            }
        }
        printf("%zd\n",minDiff);
    }
    return 0;
}
