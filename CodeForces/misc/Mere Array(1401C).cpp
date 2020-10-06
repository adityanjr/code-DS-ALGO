//https://codeforces.com/contest/1401/problem/C
//Time complexity O(nlogn)
//Space complexity O(n)

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
        int f;
        long long n;
        cin >> n;

        long long a[n],b[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
            b[i] = a[i];
        }

        sort(b,b+n);
        long long m = b[0];

        f=0;
        for(int i=0;i<n;i++){
            if(a[i]%m != 0){
                if(b[i] != a[i]){
                    f=1;
                    break;
                }
            }
        }
        if(f){
            cout << "NO\n";
        }
        else
            cout << "YES\n";
    }
}


