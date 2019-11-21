#include <iostream>
using namespace std;

int main(){

    int numCases; scanf("%d",&numCases);
    
    int numTrips,time, start, duration, freq, waitingTime;
    while(numCases--){
       scanf("%d",&numTrips);
       time = 0;
       for(int trip = 0; trip < numTrips ; trip++){
           scanf("%d %d %d",&start, &duration, &freq);
           waitingTime = (time <= start) ? (start - time) : freq - 1 - (time - start - 1)%freq ; 
           time += waitingTime + duration ;
       }
       printf("%d\n",time);
    }

    return 0;
}
