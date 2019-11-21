#include <iostream>
using namespace std;

int main(){
    int t; scanf("%d",&t);
    int temp;
    while(t--){
        scanf("%d",&temp);
        if(temp % 4 == 1){printf("ALICE\n");}
        else{printf("BOB\n");}
    }

    return 0;
}
