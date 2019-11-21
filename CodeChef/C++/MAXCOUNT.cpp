#include <iostream>
#include <map>
using namespace std;

int main(int argc, char* argv[]){

    size_t N; scanf("%zd",&N);
    
    size_t temp, n;
    for(size_t k = 0; k < N ; k++){

        map<size_t,size_t> counts;
        map<size_t,size_t>::iterator mapIter;

        scanf("%zd",&n); 
        for(size_t m = 0; m < n ; m++){
            scanf("%zd",&temp);
            if(counts.find(temp) == counts.end() ){counts[temp] = 1;}
            else{counts[temp]++ ;}
        }

        size_t currentMaxArg = 0, currentMax = 0;

        for(mapIter = counts.begin(); mapIter != counts.end() ; mapIter++){
            if((mapIter -> second) < currentMax ){continue;}
            if((mapIter -> second) == currentMax && (mapIter -> first) > currentMaxArg ){continue;}
            
            currentMaxArg = mapIter -> first;
            currentMax = mapIter -> second;
        }
        
        printf("%zd %zd\n",currentMaxArg, currentMax);
    }

    return 0;
}
