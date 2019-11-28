#include <bits/stdc++.h>
using namespace std;

int reverse(int num) {
	int temp = num, reverse = 0, remain;

    while (num > 0) {
        remain = num % 10;
        reverse = reverse * 10 + remain;
        num /= 10;
    }

    return reverse;
}


int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int temp;
		set<int> s;
		
		for(int i = 0; i < n; i ++){
			cin >> temp;
			s.insert(temp);
		}

		cout << s.size() << "\n";

	}
}