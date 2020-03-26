// http://www.geeksforgeeks.org/closest-pair-of-points
/*Incorrect*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cfloat>
using namespace std;

struct point {
	int x, y;
};

bool compare(point a, point b){
	 return (a.x < b.x);
}

bool compareY(point a, point b){
	 return (a.y < b.y);
}

float bruteForce(point *p, int n){
	float res = FLT_MAX;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			float d= sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y));
			if(res > d){ 
   				   res = d;
   			}
		}
	}
	return res;
}

float stripClosest(point *strip, int n){
	float d = FLT_MAX;
	sort(strip, strip+n, compareY);
	
	for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n && (strip[j].y - strip[i].y) < d; ++j){
        	float dist = sqrt((strip[i].x-strip[j].x)*(strip[i].x-strip[j].x) + (strip[i].y-strip[j].y)*(strip[i].y-strip[j].y));
            if (dist < d)
                d = dist;
        }
	}
	return d;
}

float closestUtil(point *p, int n){
	if(n <= 3)
		 return bruteForce(p, n);
    int mid = n/2;
    point pMid = p[mid];
    float dl = closestUtil(p, mid);
    float dr = closestUtil(p+mid, n-mid);
    float res = min(dl, dr);
  
    point strip[n];
    int j=0;
    for(int i=0; i<n; i++){
    	if(abs(p[i].x - pMid.x) < res)
			  strip[j++] = p[i];
	}
	return min(res, stripClosest(strip, j));
}

float closest(point p[], int n){
	sort(p, p+n, compare);
	return closestUtil(p, n);
}

int main() {
	point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    printf("The smallest distance is %f ", closest(P, n));
	return 0;
}


