/*
 *  This problem was asked by Google.

    The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

    Hint: The basic equation of a circle is x2 + y2 = r2.

 */   

/*
 * Monte Carlo is Randomized Algorithms. 
 * Idea is to get PI from Probability.
 *
 * consider a circle of radius 1 unit circumscribed inside the rectangle (of course the length and breadth of rectangle will be 2)
 *
 * now probability of point generated inside circle is P(__)=AREA_OF_CIRCLE / AREA_OF_RECTANGLE 
 * ==> P(__) = PI*(r*r) / 4(r*r) 
 * ==> P(__) = PI/4
 * ==> 4*P(__) = PI
 */

#include <bits/stdc++.h>
using namespace std;
int main(void){
    srand(time(NULL));
    double C{},R{}; // C = Point generated inside the Circle & R is point generated inside Rectangle 
    for(int i=0;i<100000;++i){
        double x = double((rand()%(100000+1))/100000.0f);
        double y = double((rand()%(100000+1))/100000.0f);
        if(x*x+y*y<=1.0f){
            C++;
        }
        R++;
    }
    cout<<"Expected Value of PI = "<<fixed<<setprecision(3)<<double(4.0f*C)/R<<endl;
    return 0;
}
