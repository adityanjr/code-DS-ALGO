#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    size_t N; scanf("%zd",&N);

    size_t temp;
    for(size_t k = 0; k < N ; k++){
        scanf("%zd",&temp);
        printf("%zd\n", temp - (temp % 2) );
    }

    return 0;
}
