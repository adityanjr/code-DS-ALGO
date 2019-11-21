#include <cstdio>

int main(){

    const double h = 50;
    const double c = 0.7;
    const double s = 5600;

    int t; scanf("%d\n", &t);
    while(t--){
        double x, y, z; scanf("%lf %lf %lf\n", &x, &y, &z);
        if((x > h) && (y < c) && (z > s)){puts("10");}
        else if((x > h) && (y < c)){puts("9");}
        else if((y < c) && (z > s)){puts("8");}
        else if((x > h) && (z > s)){puts("7");}
        else if((x > h) || (y < c) || (z > s)){puts("6");}
        else if(!(x > h) && !(y < c) && !(z > s)){puts("5");}
        else{puts("-1");}
    }

    return 0;
}
