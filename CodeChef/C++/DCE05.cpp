#include <iostream>
using namespace std;
int main(){
    unsigned long applicants = 0, position = 1;
    int numCases; scanf("%d\n",&numCases);
    while(numCases--){
        scanf("%lu\n",&applicants);
        position = 1; while(position <= applicants){position *= 2;}; position /= 2;
        printf("%lu\n",position);
    }
    return 0;
}
