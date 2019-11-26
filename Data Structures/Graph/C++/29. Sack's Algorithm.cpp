// # Sack' Algorithm
// The Sack algorithm allows responding offline queries related to node subtree information in a tree.
// A concept introduced in the algorithm is that of heavy son, in which the heavier nodes inherit their information to the parent (causing the heavy part of the processing to be discarded) and the lighter ones are processed normally.
// Some problems that can be solved with the Sack algorithm:
// * [Lomsat gelral - Codeforces](https://codeforces.com/problemset/problem/600/E)
// * [Tree Requests - Codeforces](https://codeforces.com/problemset/problem/570/D)
// * [Coloring Tree - HackerRank](https://www.hackerrank.com/challenges/coloring-tree/problem)
// * [Hedwig The Smart Bird - Codechef](https://www.codechef.com/problems/HEDWIG)
// * [Summing in a tree - HackerRank](https://www.hackerrank.com/contests/101hack47/challenges/summing-in-a-tree)
// * [Treedif - VJudge](https://vjudge.net/problem/SGU-507)

// Troubleshooting the above using sack:
// * [Lomsat Gelral Solution](https://notepad.pw/code/ghp6r2r2i)
// * [Tree Requests Solution](https://notepad.pw/code/vf1qu7y8)

#include <bits/stdc++.h>
using namespace std;

#define max 100007

vector<int> tree[max];
int weight[max];
vector<int> *nos[max];

void dfs(int u, int p){
    weight[u] = 1;
    for(auto v: tree[u]){
        if(v != p){
            dfs(v, u);
            weight[u] += weight[v];
        }
    }
}

void sack(int u, int p, bool keep){
    int heavy_child = -1;
    for(auto son: tree[u]){
        if(son != p){
            if(heavy_child == -1 || weight[son] > weight[heavy_child]) heavy_child = son;
        }
    }
    for(auto son: tree[u]){
        if(son != p && son != heavy_child) sack(son, u, false);
    }
    if(heavy_child == -1) nos[u] = new vector<int> ();
    else{
        sack(heavy_child, u, true);
        nos[u] = nos[heavy_child];
    } 
    nos[u]->push_back(u);
    //Operation
    for(auto son: tree[u]){
        if(son != p && son != heavy_child){
            for(auto x: *nos[son]){
                nos[u]->push_back(x);
            }
        }
    }

    // Output of sub tree u is ok

    /* Operation
    if(!keep){
        for(auto x: *nos[u]){
            
        }
    }
    */
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,1);
    sack(1,1,true);
}
