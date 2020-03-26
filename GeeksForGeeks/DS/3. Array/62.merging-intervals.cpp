// http://www.geeksforgeeks.org/merging-intervals/

#include <iostream>
#include <algorithm>
#include "array.h"

struct Interval{
    int start;
    int end;
};

bool compare(Interval a, Interval b){
	return (a.start < b.start);
}

void mergeIntervals(Interval *inter, int n){
	sort(inter, inter+n, compare);
	int j=-1;
	int start = inter[0].start;
	int end = inter[0].end;
	for(int i=1; i<n; i++){
		if(inter[i].start <= inter[i-1].end){
			end = max(end, inter[i].end);
		}
		else {
			j++;
			inter[j].start = start;
			inter[j].end = end;
			start = inter[i].start;
			end = inter[i].end;
		}
	}
	j++;
	inter[j].start = start;
	inter[j].end = end;
	for(int i=0; i<=j; i++)
		cout<<inter[i].start<<" "<<inter[i].end<<'\n';
}

int main(){
	Interval intvls[] = { {6,8},{1,3},{2,4},{4,7} };
	mergeIntervals(intvls, sizeof(intvls)/sizeof(Interval));
	return 0;
}

