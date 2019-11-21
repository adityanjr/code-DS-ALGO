#include <iostream>
using namespace std;
//By induction: Odd numbers are losing numbers, even numbers are winning;
int main(){
    size_t T; scanf("%zd",&T);
    size_t N;    
    for(size_t k = 0; k < T ; k++){
        scanf("%zd",&N);
        if(N&1){printf("BOB\n");}
        else{printf("ALICE\n");}
    }
    return 0;
}
