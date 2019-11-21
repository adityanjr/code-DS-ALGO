#include <iostream>
using namespace std;

int main(int argc, char* argv[]){

    int flag = 0;
    int n = 0; scanf("%d",&n);

    while(n > 0){
        int *perm = new int[n+1]; int *invperm = new int[n+1];
        for(size_t k = 1; k <= n; k++){ scanf("%d",(perm+k)); invperm[perm[k]] = k; }
        
        flag = 1;
        for(size_t k = 1; k<=n ; k++){ if( invperm[k] != perm[k] ){ flag = 0; break;} }
        flag ? printf("ambiguous\n") : printf("not ambiguous\n");

        scanf("%d",&n);
    }
    return 0;
}
