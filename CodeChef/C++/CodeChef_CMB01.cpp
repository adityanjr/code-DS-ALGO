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
	int n;
	scanf("%d",&n);
	while(n --) {
		int a, b, result;
		scanf("%d %d",&a,&b);
		int temp_a, temp_b, temp_result;

		temp_a = reverse(a);
		temp_b = reverse(b);

		temp_result = temp_a + temp_b;

		result = reverse(temp_result);

		printf("%d\n",result);
	}

	return 0;
}