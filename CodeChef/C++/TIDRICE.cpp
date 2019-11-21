#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){

    int numCases; scanf("%d\n",&numCases);

    const int maxLength = 20;
    int numVotes = 0, count, totalCount;
    char vote; 
    char *person = new char[maxLength];


    while(numCases--){
        scanf("%d",&numVotes);
        map<string, int> voteList;
        for(int k = 0; k < numVotes ; k++){
            scanf("%s %c\n", person, &vote);
            count = (vote == '+') ? 1 : -1;
            string name(person);
            if( voteList.find(name) == voteList.end() ){voteList.insert(pair<string,int>(name, count));}
            else{ voteList[name] = count;}
        }

        map<string,int>::iterator mapIter;
        totalCount = 0;
        for(mapIter = voteList.begin(); mapIter != voteList.end() ; mapIter++){totalCount += mapIter -> second;}
        printf("%d\n",totalCount);
    }

    return 0;
}
