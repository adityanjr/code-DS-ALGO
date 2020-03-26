// http://www.geeksforgeeks.org/job-sequencing-problem-set-1-greedy-algorithm/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct job {
	char id;
	int dead;
	int profit;
};

bool compare(job a, job b) {
	return (a.profit > b.profit );
}

void printJobScheduling(job *arr, int n){
	sort(arr, arr+n, compare);
	bool slot[n];
	int result[n];
	memset(slot, false, sizeof(slot));
	memset(result, -1, sizeof(result));
	
	for(int i=0; i<n; i++){
		for(int j=min(n, arr[i].dead)-1; j>=0; j--){
		    if(slot[j] == 0) {
				slot[j] = 1;
				result[j] = i;
				break;
			}
		}
	}
	for(int i=0; i<n; i++){
		if(slot[i])
				cout<<arr[result[i]].id<<", ";
	}
}

int main(){
   job arr[5] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs\n";
    printJobScheduling(arr, n);
    return 0;
}
