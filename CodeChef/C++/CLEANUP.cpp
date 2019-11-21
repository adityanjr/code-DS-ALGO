#include <iostream>
using namespace std;

int main(){

    size_t t; scanf("%zd",&t);
    size_t n = 0, m = 0;
    size_t currentJob, index, assigned;
    while(t--){
        scanf("%zd %zd", &n, &m);
        int *jobs = new int[n+1];
        for(size_t k = 1; k <= n ; k++){jobs[k] = -1;}
        while(m--){
            scanf("%zd",&currentJob);
            jobs[currentJob] = 0;
        }

        index = 0;
        assigned = 1;
        while(index <= n){
            index++;
            if(jobs[index] == 0){continue;}
            jobs[index] = assigned;
            assigned = 3 - assigned;
        }

        for(size_t k = 1; k <= n; k++){if(jobs[k] == 1){printf("%zd ", k);}}
        printf("\n");

        for(size_t k = 1; k <= n; k++){if(jobs[k] == 2){printf("%zd ", k);}}
        printf("\n");
    }

    return 0;
}
