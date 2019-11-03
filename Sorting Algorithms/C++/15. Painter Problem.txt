#include <iostream>
#include <climits>
using namespace std;

bool check(long int* boards, long int B, long int P, int minLen){
	int sum=0;
	P--;
	for(int i=0;i<B;i++){
		if(boards[i] > minLen)
			return false;
		if((sum+boards[i]) > minLen){
			P--;
			if(P<0){
				return false;
			}
			sum=0;
		}
		sum+=boards[i];
	}
	return true;
}
int minTime(long int* boards, long int B, long int P){
	int min = INT_MAX;
	int total =0;
	for (int i = 0; i < B; ++i){
		if(min>boards[i])
			min=boards[i];
		total+=boards[i];
	}
	int low = min, high= total, result =0;
	while(low<=high){
		int mid = low+(high-low)/2;
		bool isPossible = check(boards, B, P, mid);
		if(isPossible){
			high = mid-1;
			result = mid;
		}
		else
			low = mid+1;
	}
	return result;
}
int main(){	
	long int N, painters, time;
	long int boards[100005];
    cin>>N>>painters>>time;
    for(int i=0; i<N; i++){
        cin>>boards[i];
    }
	int minimumTime = (minTime(boards, N, painters)*time)%10000003;
	cout<< minimumTime <<endl;
	return 0;
}