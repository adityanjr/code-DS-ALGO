#include <iostream>
using namespace std;

int main(){
    int numCases; scanf("%d",&numCases);

    int N, remainder, fours, sevens;
    while(numCases--){
        scanf("%d",&N);

        remainder = N % 7;
        switch(remainder){
            case 0: sevens = 0 ;  break;
            case 1: sevens = 8 ;  break; 
            case 2: sevens = 16;  break; 
            case 3: sevens = 24;  break; 
            case 4: sevens = 4 ;  break; 
            case 5: sevens = 12;  break; 
            case 6: sevens = 20;  break; 
            default:sevens = -1;  break; 
        }
        
        fours = N - sevens;
        if(fours >= 0){printf("%d\n",fours);}
        else{printf("-1\n");}
    }
    return 0;
}
