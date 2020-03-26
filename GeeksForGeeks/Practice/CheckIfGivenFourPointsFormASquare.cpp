#include <iostream>
#include <cmath>

using namespace std;

double getDist(int a1, int b1, int a2, int b2){
    return sqrt(pow(a1-a2, 2) + pow(b1-b2, 2));
}

bool checkSame(int a1, int b1, int a2, int b2){
    if(a1 == a2 && b1 == b2){
        return true;
    }
    return false;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int a1, b1, a2, b2, a3, b3, a4, b4, ans = 0;
	    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> a4 >> b4;
	    
	    double d12 = getDist(a1, b1, a2, b2);
	    double d13 = getDist(a1, b1, a3, b3);
	    double d14 = getDist(a1, b1, a4, b4);
	    double d23 = getDist(a2, b2, a3, b3);
	    double d24 = getDist(a2, b2, a4, b4);
	    double d34 = getDist(a3, b3, a4, b4);
    
        //cout << "d12 : " << d12 << " d13 : " << d13 << " d14 : " << d14
        //<< " d23 : " << d23 << " d24 : " << d24 << " d34 : " << d34 << endl;
        
        if((d12 == d23) && (d12 == d34) && (d12 == d14) && (d24 == d13)){
            ans = 1;
        }
        else if((d12 == d13) && (d12 == d24) && (d13 == d34) && (d14 == d23)){
            ans = 1;
        }
        else if((d12 == d34) && (d13 == d14) && (d13 == d23) && (d24 == d23)){
            ans = 1;
        }
    
        cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
