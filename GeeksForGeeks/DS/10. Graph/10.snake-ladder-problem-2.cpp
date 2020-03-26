// http://www.geeksforgeeks.org/snake-ladder-problem-2

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
    int v;
    int dist;
};   

typedef queue<node> QN;

int getMinDiceThrows(int *moves, int N){
    bool visit[N];
    fill(visit, visit+N, false);
    QN q;
    node tmp = {0, 0};
    q.push(tmp);
    node ptr;
    while(!q.empty()){
        ptr = q.front();
        if(ptr.v == N-1)
            break;
        q.pop();
        for(int i=ptr.v+1; i<=ptr.v+6; i++){
            tmp.v = i;
            tmp.dist = ptr.dist+1;
            if(moves[i] == -1){
                q.push(tmp);
            }
            else {
                tmp.v = moves[i];
                q.push(tmp);
            }
        }
    }
    return q.front().dist;
}

int main(){
    int N = 30;
    int moves[N];
    for (int i = 0; i<N; i++)
        moves[i] = -1;
 
    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
 
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
 
    cout << "Min Dice throws required is " << getMinDiceThrows(moves, N);
    getchar();
    return 0;
}
