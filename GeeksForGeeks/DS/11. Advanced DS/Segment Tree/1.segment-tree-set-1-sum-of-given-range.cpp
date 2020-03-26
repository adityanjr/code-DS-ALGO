//

#include <iostream>
#include <cmath>
using namespace std;

int constructUtil(int *arr, int start, int end, int* st, int idx){
    if(start == end){
        st[idx] = arr[start];
        return arr[start];
    }
    int mid = (start + end)/2;
    st[idx] = constructUtil(arr, start, mid, st, 2*idx+1) + constructUtil(arr, mid+1, end, st, 2*idx+2);
    return st[idx];
}

int* constructST(int *arr, int n){
    int max_size = ceil(log2(n));
    int m = 2*pow(2, max_size) - 1;
    int *st = new int[m];
    constructUtil(arr, 0, n-1, st, 0);
    return st;
}

int getSumUtil(int *st, int qs, int qe, int ststart, int stend, int idx){
    if(qs <= ststart && qe >= stend){
        return st[idx];
    }
    if(qe < ststart || qs > stend)
        return 0;
    int mid = (ststart+stend)/2;
    return getSumUtil(st, qs, qe, ststart, mid, 2*idx+1) +
                getSumUtil(st, qs, qe, mid+1, stend, 2*idx+2);
}

int getSum(int *arr, int n, int qs, int qe){
    return getSumUtil(arr, qs, qe, 0, n-1, 0);
}

void updateUtil(int *st, int idx, int start, int end, int diff, int originalIdx){
    st[idx] += diff;
    if(start == end){
        return;
    }
    int mid = (start+end)/2;
    if(originalIdx <= mid){
        updateUtil(st, 2*idx+1, start, mid, diff, originalIdx);
    }
    else {
        updateUtil(st, 2*idx+2, mid+1, end, diff, originalIdx);
    }
}

int updateValue(int *arr, int *st, int n, int idx, int val){
    int diff = val - arr[idx];
    updateUtil(st, 0, 0, n-1, diff, idx);
}

int main(){
     int arr[] = {1, 3, 5, 7, 9, 11};
     int n = sizeof(arr)/sizeof(arr[0]);

     int *st = constructST(arr, n);

     printf("Sum of values in given range = %d\n", getSum(st, n, 1, 3));

     updateValue(arr, st, n, 1, 10);

     printf("Updated sum of values in given range = %d\n", getSum(st, n, 1, 3));
     return 0;
}
