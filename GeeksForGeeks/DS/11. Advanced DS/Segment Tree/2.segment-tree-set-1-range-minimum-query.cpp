// http://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query

#include <bits/stdc++.h>
using namespace std;

int constructUtil(int *arr, int start, int end, int idx, int* st){
    if(start == end){
        st[idx] = arr[start];
        return st[idx];
    }
    int mid = (start + end)/2;
    st[idx] = min(constructUtil(arr, start, mid, 2*idx+1, st),
                constructUtil(arr, mid+1, end, 2*idx+2, st));
    return st[idx];
}

int* constructST(int *arr, int n){
    int max_size = ceil(log2(n));
    int m = 2*pow(2, max_size) -1;
    int *st = new int[m];
    constructUtil(arr, 0, n-1, 0, st);
    return st;
}

int RMQUtil(int *st, int start, int end, int qs, int qe, int idx){
    if(start >= qs && qe >= end)
        return st[idx];
    if(start > qe || end < qs)
        return INT_MAX;
    int mid = (start+end)/2;
    return min(RMQUtil(st, start, mid, qs, qe, 2*idx+1), RMQUtil(st, mid+1, end, qs, qe, 2*idx+2));
}

int RMQ(int *st, int n, int qs, int qe){
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}

int main(){
    int arr[] = {1, 3, 2, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    int *st = constructST(arr, n);


    int qs = 1;  // Starting index of query range
    int qe = 5;  // Ending index of query range

    printf("Minimum of values in range [%d, %d] is = %d\n",
                    qs, qe, RMQ(st, n, qs, qe));
    return 0;
}
