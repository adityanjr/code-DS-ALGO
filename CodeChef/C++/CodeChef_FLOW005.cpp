#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int count(int arr[], int m, int n )
{
    int table[n+1];
 
    memset(table, 0, sizeof(table));
 
    table[0] = 1;
 
    for(int i=0; i<m; i++)
        for(int j=arr[i]; j<=n; j++)
            table[j] += table[j-arr[i]];
 
    return table[n];
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		v.clear();
		int m = 6, n,temp;
		scanf("%d",&n);

		// v = {1, 2, 5, 10, 50, 100};
		int arr[] = {1, 2, 5, 10, 50, 100};
		// v.push_back(1);
		// v.push_back(2);
		// v.push_back(5);
		// v.push_back(10);
		// v.push_back(50);
		// v.push_back(100);

		printf("%d\n",count(arr, m-1, n) );
	}
	return 0;
}