#include <bits/stdc++.h>
using namespace std;

long long int reverse(long long int num) {
	long long int temp = num, reverse = 0, remain;

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
	while(n--) {
		int x, temp_x;
		scanf("%d",&x);

		long long int result, flag = 1, count = 0;

		while(flag){
			temp_x = reverse(x);
			result = x + temp_x;
			if(result == reverse(result))
				flag = 0;
			else
				x = result;
			count ++;
		}
		
		printf("%lld %lld\n",count,result);
	}
}