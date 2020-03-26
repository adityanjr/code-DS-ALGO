// http://www.geeksforgeeks.org/minimum-cost-polygon-triangulation

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000.0

struct Point {
	int x, y;
};

double dist(Point p1, Point p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
                (p1.y - p2.y)*(p1.y - p2.y));
}

double cost(Point *p, int i, int j, int k){
	return dist(p[i], p[j]) + dist(p[j], p[k]) + dist(p[k], p[i]);
}

double mTC(Point *p, int n){
	if(n<3)
		return 0;

	double cache[n][n];
	for(int gap=0; gap<n; gap++){
		for(int i=0, j=gap; j<n; i++, j++){
			if(j-i < 2)
				cache[i][j] = 0.0;
			else {
				cache[i][j] = MAX;
				for(int k=i+1; k<j; k++){
					cache[i][j] = min(cache[i][j], cache[i][k] + cache[k][j] + cost(p, i, j, k));
				}
			}
		}
	}
	return cache[0][n-1];
}

int main(){
	Point points[] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};
    int n = sizeof(points)/sizeof(points[0]);
    cout << mTC(points, n);
	return 0;
}

