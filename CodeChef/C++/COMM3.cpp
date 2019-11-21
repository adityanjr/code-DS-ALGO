#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int t; scanf("%d",&t);
    int R;
    int firstX,firstY,secondX,secondY,thirdX,thirdY;
    double dxy, dyz, dzx;
    bool a,b,c;

    while(t--){
        scanf("%d",&R);

        scanf("%d %d ",&firstX,  &firstY);
        scanf("%d %d ",&secondX, &secondY);
        scanf("%d %d ",&thirdX,  &thirdY);
        
        dxy = sqrt( pow(firstX  - secondX,2) + pow(firstY  - secondY,2));
        dyz = sqrt( pow(secondX - thirdX,2)  + pow(secondY - thirdY,2));
        dzx = sqrt( pow(thirdX  - firstX,2)  + pow(thirdY  - firstY,2));
        
        a = (dxy <= R) && (dzx <= R);
        b = (dxy <= R) && (dyz <= R);
        c = (dzx <= R) && (dyz <= R);

        if( a || b || c){printf("yes\n");}
        else{printf("no\n");}
    }
    return 0;
}
