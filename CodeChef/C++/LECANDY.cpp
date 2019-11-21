#include <iostream>
using namespace std;

int main(){
    int t; scanf("%d",&t);
    size_t temp, sum, N, C;
    while(t--){
        scanf("%zd %zd",&N, &C);
        sum = 0;
        for(size_t k = 0; k < N ; k++){
            scanf("%zd",&temp);
            sum += temp;
        }
        if(sum <= C){printf("Yes\n");}
        else{printf("No\n");}
    }

    return 0;
}
