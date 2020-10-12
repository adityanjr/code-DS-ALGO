#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,i;
    cin >> n;

    vector<long long int> f;
    f.push_back(0);
    f.push_back(1);

    if (n == 0) {
        cout << n;
    }
    else if (n == 1) {
        cout << n;
    }
    else {
        for (i = 2; i <= n; i++) {
            f.push_back((f[i - 1] + f[i - 2])%10);
        }
        cout << f[n];
    }
    
}