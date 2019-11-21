#include <iostream>
#include <algorithm>
using namespace std;

size_t NChooseK(int n,int k){
    size_t output = 1;
    for(size_t u = n-k+1; u <=n ; u++){output *= u;}
    for(size_t u = 1; u <=k ; u++){output /= u;}
    return output;
}

int main(){

    int testCases; scanf("%d",&testCases);
    const int numPlayers = 11;
    int scores[numPlayers];
    int K, minScore, before, after;

    while(testCases--){

        for(int k = 0; k < numPlayers ; k++){scanf("%d",(scores + k));}
        scanf("%d",&K);
        sort(scores, scores + numPlayers);
        minScore = scores[numPlayers - K];
        before = 0; after = 0;
        for(int u = 1; u <= numPlayers - K ; u++){if(scores[numPlayers - K - u] == minScore ) {before++;}}
        for(int u = 1; u <= K-1            ; u++){if(scores[numPlayers - K + u] == minScore ) {after++;} }
        printf("%zd\n",NChooseK(before + after + 1, after + 1));
    }
    return 0;
}
