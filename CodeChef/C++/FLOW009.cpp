#include <cstdio>

int main(){

    const double Q = 1000.0;
    const double mult = 0.9;
    int t; scanf("%d\n", &t);
    while(t--){
        double q, p; scanf("%lf %lf\n", &q, &p);
        if(q > Q){p *= mult;}
        printf("%.6lf\n", p * q);
    }

    return 0;
}
