// http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations

#include <iostream>
#include <cstdio>
using namespace std;

struct _ {
    int petrol, dist;
};

int printTour(_ *arr, int n){
    int max_sum = 0;
    int idx = 0;
    int Max = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i].petrol - arr[i].dist;
        if(max_sum < 0){
            max_sum = 0;
            idx = i;
        }
        max_sum += arr[i].petrol - arr[i].dist;
        if(Max < max_sum){
            Max = max_sum;
        }
    }
    if(sum>=0)
        return idx;
    return -1;
}

int main(){
    _ arr[] = {{6, 4}, {3, 6}, {7, 3}};

    int n = sizeof(arr)/sizeof(arr[0]);
    int start = printTour(arr, n);

    (start == -1)? printf("No solution"): printf("Start = %d", start);
    getchar();
}
