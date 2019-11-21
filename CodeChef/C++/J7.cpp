#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]){
    
    size_t N; scanf("%zd",&N);
    float L, S, D; 
    double x, y, z, vol;

    for(size_t k = 0; k < N ; k++){
        scanf("%f %f",&L,&S);
        D = sqrt(L*L - 24*S);
        x = (L - D) / 12.0;
        y = (L - D) / 12.0;
        z = (L +2*D) / 12.0;
        vol = x * y * z;
        printf("%.2f\n",vol);
    }
    return 0;
}
