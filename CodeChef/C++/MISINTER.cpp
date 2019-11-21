#include <iostream>
using namespace std;
 
int main(){
 
    long power = 0; size_t output = 1;
    int N = 0, start = 0, temp = 0, stateMod = 0;
    const size_t ansMod = 1000000007; 
    const int numLetters = 26;
 
    int numCases; scanf("%d\n",&numCases);
    while(numCases--){
        scanf("%d", &N);
        bool *state = new bool[N];
        
        for(int k = 0; k < N ; k++){state[k] = 0;}
        stateMod = 2*(N/2) + 1;
        power = 0;
 
        while(true){
            for(start = 0; state[start] == 1 && start < N; start++);
            if(start == N){break;}
            temp = start;
            while(!state[temp]){state[temp] = 1; temp = (2 * temp + 1)%stateMod;}
            power++;
        }
        output = 1;
        for(int k = 0; k < power ; k++){output *= numLetters; output %= ansMod;} 
        printf("%zd\n",output);
    }
    return 0;
}