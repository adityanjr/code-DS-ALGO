#include <cstdio>
#include <cmath>


int main(){

    int T; scanf("%d\n", &T);

    while(T--){
        double b, ls; scanf("%lf %lf\n", &b, &ls);
        printf("%.4lf %.4lf\n", sqrt(ls * ls - b * b), sqrt(ls * ls + b * b));
    }

    return 0;
}
