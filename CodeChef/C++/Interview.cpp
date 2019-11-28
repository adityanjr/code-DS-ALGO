#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    
    int val;
    scanf("%d",&val);
    
    for(int j = 0; j < n; j ++) {
        if(arr[n-1][j] == val){
            printf("%d %d",i,j);
            exit(0);
        }
        else if(arr[n-1][j] < val){;}
        else if(arr[n-1][j] > val){
            for(int i = n-2; i >= 0; i --) {
                if(arr[i][j] == val) {
                    printf("%d %d",i,j);
                    exit(0);
                }
            } 
        }
    }
    return 0;
 }
