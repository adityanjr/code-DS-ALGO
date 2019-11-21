#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    size_t N,temp;
    scanf("%zd",&N);
    for(size_t k = 0; k < N ; k++){
        scanf("%zd",&temp);
        printf("%zd\n",1 + temp/2);
    }
    return 0;
}
