#include <iostream>
#include <algorithm>
using namespace std;
bool check(long long *stalls, long int N, long int C, int minDiff){
	C--; // first cow is placed at stalls[0];
	int prevCow = 0;
	for (int i=1; i<N; i++){
		if((stalls[i] - stalls[prevCow]) >= minDiff ){
			C--;
			prevCow = i;
			if(C==0)
				return true;
		}
	}
	return false;
}
int binarySearch(long long *stalls, long int N, long int C){
	sort(stalls, stalls+N);
	int result = 0;
	int low =stalls[0], high = stalls[N-1];
	while(low <= high){
		int mid = low + (high-low)/2;
		bool isPossible = check(stalls, N, C, mid);
		if(isPossible){
			low = mid+1;
			result = mid;
		}
		else
			high = mid-1;
	}
	return result;
}
int main(){
	long long stalls[1000005];
	long int N, C;
    cin>>N>>C;
    for(int i=0; i<N; i++){
        cin>>stalls[i];
    }
	cout<<binarySearch(stalls, N, C)<<endl;
	return 0;
}
