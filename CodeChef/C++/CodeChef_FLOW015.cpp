#include <bits/stdc++.h>
using namespace std;

string days[7]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main() {
	int t;
	scanf("%d",&t);
	
	while(t --) {
		int n;
		scanf("%d", &n);

		int offset = n - 1900;
        for( int i = 1900; i < n; i++ ) {
            if( i % 4 == 0 ) {
                if( i % 100 == 0 && i % 400 != 0 ) {
                    offset += 0;
                }
                else {
                    offset += 1;
                }
            }
            else {
                offset += 0;
            }
        }
        offset = offset % 7;
		cout << days[offset] << endl;
	}

	return 0;
}