#include <iostream>
using namespace std;

int main(){

    size_t firstScore = 0 , secondScore = 0, newFirst = 0, newSecond = 0; 
    size_t winner = 1, maxLead = 0, currentDiff = 0;
    size_t numRounds; scanf("%zd",&numRounds);

    for(size_t currentRound = 1 ; currentRound <= numRounds ; currentRound++){
        scanf("%zd", &newFirst); scanf("%zd",&newSecond);
        firstScore += newFirst; secondScore += newSecond;
        currentDiff = (firstScore > secondScore) ? (firstScore - secondScore) : (secondScore - firstScore);
        if(maxLead >= currentDiff){continue;}
        maxLead = currentDiff;
        winner = (firstScore > secondScore) ? 1 : 2;
    }
    printf("%zd %zd", winner , maxLead);

    return 0;
}
