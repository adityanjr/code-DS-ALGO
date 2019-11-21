#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){

    size_t N; cin >> N;
    vector<size_t> perm(N+1,0);
    for(size_t k = 1 ; k <= N ; k++){scanf("%zd",&perm[k]);}

    vector< vector<size_t> > cycleList;

    size_t currentIndex = 0, temp = 0, counter = 0;
    while(currentIndex <= N){
        currentIndex = 0;
        while(currentIndex <= N && perm[currentIndex] == 0){currentIndex++;}
        if(currentIndex > N){break;}
        counter++;

        vector<size_t> currentCycle;
        currentCycle.push_back(currentIndex);
        do{
            temp = perm[currentIndex];
            currentCycle.push_back(temp);
            perm[currentIndex] = 0; 
            currentIndex = temp;
        }while(perm[currentIndex] != 0);

        cycleList.push_back(currentCycle);
    }
    

    printf("%zd\n",counter);
    for(size_t n = 0; n < cycleList.size() ; n++){
        for(size_t k = 0; k < cycleList[n].size() ; k++){printf("%zd ",cycleList[n][k]);}
        printf("\n");
    }

    return 0;
}
