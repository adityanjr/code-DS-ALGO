// http://www.geeksforgeeks.org/greedy-algorithms-set-1-activity-selection-problem

#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void func(int start[], int finish[], int n){
	//sort a/c to finish time
	for (int i = 0; i < n; ++i){
		for (int j = i+1; j < n; ++j) {
			if (finish[j] < finish[i]) {
				swap(finish[j], finish[i]);
				swap(start[j], start[i]);
			}
			else if(finish[j] == finish[i] && start[j] < start[i]) {
				swap(finish[j], finish[i]);
				swap(start[j], start[i]);
			}
		}
	}

	cout<<start[0]<<"->"<<finish[0]<<", ";
	int t = finish[0];
	for (int i = 1; i < n; ++i)	{
		if(t <= start[i]) {
			cout<<start[i]<<"->"<<finish[i]<<", ";
			t = finish[i];
		}
	}
}

int main(){
	int start[]  =  {1, 3, 0, 5, 8, 5};
    int finish[] =  {2, 4, 6, 7, 9, 9};
    func(start, finish, sizeof(start)/sizeof(*start));
	return 0;
}