// http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/

#include <iostream>
#include <algorithm>
using namespace std;

int lis(int *arr, int n){
    int *res = new int[n];
    fill(res, res+n, 1);
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && res[j] >= res[i])
                res[i] = res[j] + 1;
        }
    }
    int m = 1;
    for(int i=0; i<n; i++)
        m = max(m, res[i]);
    return m;
}

//Res will contain max of all previous results
int lisRec(int *arr, int *res, int n){
    if(res[n-1])
        return res[n-1];
    int m = 1;
    for(int i=0; i<n-1; i++){
        int tmp = lisRec(arr, res, i+1);
        if(arr[i] < arr[n-1] && m <= tmp)
            m = tmp + 1;
    }
    res[n-1] = m;
    res[n-1] = max(res[n-1], res[n-2]);
    return res[n-1];
}

//To calculate length of LIS in O(nlogn)
int lis1(int *arr, int n){
	vector<int> s;
	for(int i=0; i<n; i++){
		if(s.empty() || s.back() < arr[i]){
			s.push_back(arr[i]);
		}
		else {
			int idx = upper_bound(s.begin(), s.end(), arr[i]) - s.begin();
			s[idx] = arr[i];
		}
	}
	return s.size();
}

int main() {
    int arr[] = { 10, 22, 10, 33, 21, 50, 55, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d\n", lis( arr, n ) );
    int res[n];
    fill(res, res+n, 0);
    printf("Length of LIS is %d\n", lisRec(arr, res, n ) );
	return 0;
}


