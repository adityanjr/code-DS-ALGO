// http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance

#include <iostream>
#include <cstring>
using namespace std;

int EditDistanceDP(char *X, char *Y){
    int m = strlen(X);
    int n = strlen(Y);
    int cache[m+1][n+1];

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0)
                cache[0][j] = j;
            else if(j==0)
                cache[i][0] = i;
            else
                cache[i][j] = 0;
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            int tmp = INT_MAX;
            if(X[i-1] == Y[j-1])
                tmp = cache[i-1][j-1];

            tmp = min(tmp, cache[i-1][j-1]+1);
            tmp = min(tmp, cache[i-1][j]+1);
            tmp = min(tmp, cache[i][j-1]+1);
            cache[i][j] = tmp;
        }
    }

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            cout<<cache[i][j]<<" ";
        }
        cout<<'\n';
    }
    return cache[m][n];
}

int main() {
    char Y[] = "SATURDAY"; // vertical
    char X[] = "SUNDAY"; // horizontal

    printf("Minimum edits required to convert %s into %s is %d\n",
           X, Y, EditDistanceDP(X, Y) );
/*    printf("Minimum edits required to convert %s into %s is %d by recursion\n",
           X, Y, EditDistanceRecursion(X, Y, strlen(X), strlen(Y)));*/
	return 0;
}


