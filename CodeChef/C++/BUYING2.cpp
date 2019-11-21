#include <iostream>
using namespace std;

int main(){

    int numCases; scanf("%d",&numCases);
    const int maxNote = 1000;
    int N, X, minNote, value; 
    
    while(numCases--){
        
        scanf("%d %d",&N, &X);
        int *banknotes =  new int[N];
        value = 0, minNote = maxNote;
        for(int k = 0; k < N; k++){
            scanf("%d",banknotes + k);
            minNote = min(minNote, banknotes[k]);
            value += banknotes[k];
        }
        
        if(value % X >= minNote){printf("-1\n");}
        else{printf("%d\n", value / X);}
    }

    return 0;
}
