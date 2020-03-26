//

// http://www.geeksforgeeks.org/maximum-contiguous-circular-sum/

#include<iostream>
using namespace std;

int maxSum(int *a, int n){
	int sumHere = 0;
	int after = 0;
	int m = 0;
	for(int i=0; i<n; i++){
		if(a[i]<0){
			m = max(m, after);
			after = 0;
		}
		else{
			after += a[i];
		}
		sumHere += a[i];
		m = max(m, sumHere);
	}
	m = max(m, after);
}

int maxCircularSum(int *a, int n){
	int b[2*n];
	for(int i=0; i<n; i++){
		b[i] = b[n+i] = a[i];
	}
	return maxSum(b, 2*n);
}

/*Kadane's Method*/
int kadane(int *a, int n){
    int max_sum=0, Max=INT_MIN;
    for(int i=0; i<n; i++){
        if(max_sum<0){
            max_sum = 0;
        }
        max_sum += a[i];
        Max = max(Max, max_sum);
    }
    return Max;
}

int maxCircularSum1(int *a, int n){
    int tmp = kadane(a, n);
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
        a[i] *= -1;
    }
    return max(tmp, sum + kadane(a, n));

}

int main() {
	int a[] =  {11, 10, -20, 5, -3, -5, 8, -13, 10};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Maximum circular sum is %d\n", maxCircularSum(a, n));
    printf("Maximum circular sum is %d\n", maxCircularSum1(a, n));
    getchar();
	return 0;
}
