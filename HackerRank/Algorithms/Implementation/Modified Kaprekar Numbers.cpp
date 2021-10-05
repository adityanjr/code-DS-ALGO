#include <iostream>
#include <math.h>
using namespace std;
#define ll long long

bool isKaprekar(int n) {
    int cnt = 0;
    int temp = n;
    long nsquare = pow(n,2);

    while (temp > 0) {
        cnt++;
        temp = temp / 10;
    }
    if (((nsquare % (long)pow(10, cnt)) + (nsquare / (long)pow(10, cnt))) == (long)n)
        return 1;

    return 0;
}

int main() {
    int p,q;
    bool flag = false;
    cin >> p >> q;

    for (int i = p; i <= q; i++) {
        if(isKaprekar(i)) {
            flag = true;
            cout << i << " ";
        }
    }
    
    if (!flag)
        cout << "INVALID RANGE" << endl;
    
    return 0;
}