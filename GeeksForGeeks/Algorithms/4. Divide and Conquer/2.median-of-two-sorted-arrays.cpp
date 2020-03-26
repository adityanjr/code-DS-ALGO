//http://www.geeksforgeeks.org/median-of-two-sorted-arrays

#include <iostream>
#include <cstdio>
using namespace std;

int getMedianUtil(int *a, int starta, int enda, int *b, int startb, int endb){
    if(starta > enda || startb > endb)
        return -1;
    int n = enda-starta+1;
    if(n==1){
        return (a[starta]+b[startb])/2;
    }
    int mida = (starta+enda)/2;
    int midb = (startb+endb)/2;
    if(n%2){
        if(a[mida] > b[midb]){
            return getMedianUtil(a, starta, mida, b, midb, endb);
        }
        else {
            return getMedianUtil(a, mida, enda, b, startb, midb);
        }
    }
    else {
        if(a[mida] + a[mida+1] > b[midb] + b[midb+1]){
            return getMedianUtil(a, starta, mida, b, midb+1, endb);
        }
        else {
            return getMedianUtil(a, mida+1, enda, b, startb, midb);
        }
    }

}

int getMedian(int *a, int *b, int n){
    return getMedianUtil(a, 0, n-1, b, 0, n-1);
}

int main(){
    int ar1[] = {1, 12, 16, 26, 38};
    int ar2[] = {2, 13, 16, 30, 45};

    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
        printf("Median is %d", getMedian(ar1, ar2, n1));
    else
        printf("Doesn't work for arrays of unequal size");
    return 0;
}
