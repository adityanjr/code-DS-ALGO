// http://www.geeksforgeeks.org/mobile-numeric-keypad-problem

#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x);
#define LL long long
#define LD long double
#define PB push_back
#define INF 2000000009

typedef vector<int> VI;

int row[] = {0, 0, -1, 0, 1};
int col[] = {0, -1, 0, 1, 0};

bool isSafe(char keyword[4][3], int i, int j){
    if(i<0 || i>3 || j<0|| j>2)
        return false;
    char tmp = keyword[i][j];
    if(tmp >= '0' && tmp <= '9')
        return true;
    return false;
}

int getCount(char keyword[4][3], int N){
	int cache[N+1][10];
	for(int i=0; i<10; i++){
		cache[0][i] = 0;
		cache[1][i] = 1;
	}
	for(int n=2; n<=N; n++){
		//One row
		for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                //One spot
                if(keyword[i][j] == '*' || keyword[i][j] == '#')
                    continue;
                int tmp = 0;
                for(int k=0; k<5; k++){
                    if(!isSafe(keyword, i+row[k], j+col[k]))
                        continue;
                    tmp += cache[n-1][keyword[i+row[k]][j+col[k]] - int('0')];
                }
                cache[n][keyword[i][j]-int('0')] = tmp;
            }
		}
	}
	int count = 0;
	for(int i=0; i<10; i++)
        count += cache[N][i];
    return count;
}

int main(){
	char keypad[4][3] = {{'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'},
                        {'*','0','#'}};
   printf("Count for numbers of length %d: %d\n", 1, getCount(keypad, 1));
   printf("Count for numbers of length %d: %d\n", 2, getCount(keypad, 2));
   printf("Count for numbers of length %d: %d\n", 3, getCount(keypad, 3));
   printf("Count for numbers of length %d: %d\n", 4, getCount(keypad, 4));
   printf("Count for numbers of length %d: %d\n", 5, getCount(keypad, 5));
	return 0;
}

