#include <iostream>
#include <climits>
using namespace std;

int main(){

    int t; scanf("%d",&t);
    int n,currentMin,currentSpeed,maxSpeedCars;
    while(t--){
        scanf("%d",&n);
        currentMin = INT_MAX;

        maxSpeedCars = 0;
        for(int k = 0; k < n ; k++){
            scanf("%d",&currentSpeed);
            if(currentSpeed <= currentMin){
                currentMin = currentSpeed;
                maxSpeedCars++;
            }
        }
        printf("%d\n",maxSpeedCars);
    }

    return 0;
}
