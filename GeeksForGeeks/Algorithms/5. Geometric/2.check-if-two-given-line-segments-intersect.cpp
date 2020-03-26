// http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect

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

bool onSegment(point p, point q, point r){
	if(q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
       q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
         return true;
    return false;
}

bool doIntersect(point p1, point q1, point p2, point q2) {
	 int o1 = orientation(p1, q1, p2);
	 int o2 = orientation(p1, q1, q2);
	 int o3 = orientation(p2, q2, p1);
	 int o4 = orientation(p2, q2, q1);
	 
	 if(o1 != o2 && o3 != o4)
	 	   return true;
     if(o1 == 0 && onSegment(p1, p2, q1))
  	 	   return true;
     if(o2 == 0 && onSegment(p1, q2, q1))
  	 	   return true;
     if(o3 == 0 && onSegment(p2, p1, q2))
  	 	   return true;
     if(o4 == 0 && onSegment(p2, q1, q2))
  	 	   return true;
}

int main() {
	point p1 = {1, 1}, q1 = {10, 1};
    point p2 = {1, 2}, q2 = {10, 2};
 
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
 
    p1 = {10, 0}, q1 = {0, 10};
    p2 = {0, 0}, q2 = {10, 10};
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
 
    p1 = {-5, -5}, q1 = {0, 0};
    p2 = {1, 1}, q2 = {10, 10};
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
	return 0;
}


