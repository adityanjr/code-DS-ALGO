#include<cstdio>
#include<set>

int main(){

    int firstSize, secondSize, thirdSize;
    scanf("%d %d %d", &firstSize, &secondSize, &thirdSize);

    std::set<int> first, second, third, output;
    for(int k = 0; k < firstSize; k++){int temp; scanf("%d", &temp); first.insert(temp);}
    for(int k = 0; k < secondSize; k++){int temp; scanf("%d", &temp); second.insert(temp);}
    for(int k = 0; k < thirdSize; k++){int temp; scanf("%d", &temp); third.insert(temp);}


    std::set<int>::iterator setIter;
    for(setIter = first.begin(); setIter != first.end(); setIter++){if(second.find(*setIter) != second.end() || third.find(*setIter) != third.end()){output.insert(*setIter);}}
    for(setIter = second.begin(); setIter != second.end(); setIter++){if(third.find(*setIter) != third.end()){output.insert(*setIter);}}

    printf("%ld\n", output.size());
    for(setIter = output.begin(); setIter != output.end(); setIter++){printf("%d\n", *setIter);}; puts("");

    return 0;
}
