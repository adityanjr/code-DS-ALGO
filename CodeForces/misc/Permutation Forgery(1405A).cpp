//https://codeforces.com/contest/1405/problem/A
//Time complexity: O(n)
//Space complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case=1;
    cin >> test_case;
    while(test_case--) {
        long long n;
        cin >> n;
        long long a[n];
        for(int i= 0; i<n; i++)
            cin >> a[i];
        
        for(int i=n-1; i>=0; i--) // Just reverse the array and problem is solved!
            cout << a[i] << " ";
        cout << endl;
    }
}
