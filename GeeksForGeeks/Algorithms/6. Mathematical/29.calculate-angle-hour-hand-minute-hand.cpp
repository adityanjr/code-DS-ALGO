// http://www.geeksforgeeks.org/calculate-angle-hour-hand-minute-hand/

#include <iostream>
#include <cmath>
using namespace std;

int calcAngle(int h, int m){
    h = h%12 + m/60;
    m = m%60;
    int mAngle = 6*m;
    int hAngle = 30*h + m/2;
    int res = abs(mAngle - hAngle);
    return min(360-res, res);
}

int main(){
    printf("%d \n", calcAngle(9, 60));
    printf("%d \n", calcAngle(3, 30));
    return 0;
}
