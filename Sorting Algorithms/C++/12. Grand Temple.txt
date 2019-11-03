#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int>x;
    vector<int>y;
    int xc,yc;
    for(int i=0;i<n;i++){
        cin>>xc>>yc;
        x.push_back(xc);
        y.push_back(yc);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int dx=0,dy=0;
    for(int i=0;i<n-1;i++){
        dx = max(dx, x[i+1]-x[i]);
        dy = max(dy, y[i+1] - y[i]);
    }
    cout<<(dx-1)*(dy-1);
	return 0;
}