#include <iostream>
using namespace std;

int main(){

    int numCases; scanf("%d\n",&numCases);
    int numGames = 0, I = 0, Q = 0;
    size_t N = 0;

    while(numCases--){
        scanf("%d\n",&numGames);
        while(numGames--){
            scanf("%d %zd %d\n", &I , &N , &Q);
            if( N%2 == 1 && I != Q){printf("%zd\n",(N+1)/2);}
            else{printf("%zd\n",N/2);}
        }
    }
    return 0;
}
