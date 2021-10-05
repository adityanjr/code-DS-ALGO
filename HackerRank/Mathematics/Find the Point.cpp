#include <iostream>
using namespace std;

int main() {
    
    int n, px, py, mx, my;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        
        cin >> px >> py >> mx >> my;
        
        int rx = 2 * mx - px;
        int ry = 2 * my - py;
        
        cout << rx << " " << ry << endl;
    }
    
    return 0;
}