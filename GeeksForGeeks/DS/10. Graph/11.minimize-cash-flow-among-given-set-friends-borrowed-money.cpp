// http://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/

#include <iostream>
#include <algorithm>
using namespace std;

#define N 5

struct _ {
    int v;
    int credit;
};

bool compare(_ a, _ b){
    return (a.credit < b.credit);
}

void minCashFlow(int graph[][N]){
    //debitor -> negative
    _ net[N];
    for(int i=0; i<N; i++){
        int tmp = 0;
        for(int j=0; j<N; j++){
            tmp -= graph[i][j];
            tmp += graph[j][i];
        }
        net[i].v = i;
        net[i].credit = tmp;
    }
    sort(net, net+N, compare);
    int i=0, j=N-1;
    while(i < j){
        if(net[i].credit == -net[j].credit){
            cout<<net[i].v<<"-->"<<net[j].v<<"=="<<net[j].credit<<'\n';
            i++;    j--;
        }
        else {
            int tmp = min(-net[i].credit, net[j].credit);
            cout<<net[i].v<<"-->"<<net[j].v<<"=="<<tmp<<'\n';
            if(net[i].credit == -tmp){
                i++;
                net[j].credit -= tmp;
            }
            else {
                j--;
                net[i].credit += tmp;
            }
            sort(net+i, net+j+1, compare);
        }
    }
}

int main(){
    // graph[i][j] indicates the amount that person i needs to
    // pay person j
    int graph[N][N] = { {0, 10, 20, 0, 0},
                        {0, 0, 0, 5, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 5, 0, 0}
    };
    // Print the solution
    minCashFlow(graph);
    getchar();
    return 0;
}
