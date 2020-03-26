// http://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping

#include <iostream>
#include <cmath>
using namespace std;

struct point {
    int x, y;
};

int orientation(point p, point q, point r){
	int val = (q.y-p.y) * (p.x-r.x) -
			  (q.x-p.x) * (p.y-r.y);
    if(val == 0)
	   return 0;
    return (val > 0 ? 1:2);
}

void convexHull(point *p, int n) {
    if(n < 3)
        return;
    int next[n];
    int l = 0;
    for(int i=0; i<n; i++){
        next[i] = -1;
        if(p[i].x < p[l].x)
            l = i;
    }
    int r=l, q;
    do {
        q = (r+1)%n;
        for(int i=0; i<n; i++){
            if(orientation(p[r], p[i], p[q]) == 2){
                q = i;
            }
        }
        next[r] = q;
        r = q;
    }
    while(r != l);
    for(int i=0; i<n; i++){
        if(next[i] != -1)
            cout<<"("<<p[i].x<<", "<<p[i].y<<")\n";
    }
}

int main() {
    point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
	return 0;
}


