//  https://www.interviewbit.com/problems/commutable-islands/

int find(int parent[], int i) {
    if(parent[i]==-1)
        return i;
    return find(parent, parent[i]);
}
void Union(int parent[], int x, int y) {
    int xp = find(parent, x);
    int yp = find(parent, y);
    parent[xp] = yp;
}
bool comp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
int Solution::solve(int A, vector<vector<int> > &B) {
    
    sort(B.begin(), B.end(), comp);
    
    int parent[A];
    fill_n(parent, A, -1);
    
    int ans = 0;
    
    for(int i=0;i<B.size();i++) {
        int up = find(parent, B[i][0]-1);
        int vp = find(parent, B[i][1]-1);
        
        if(up!=vp) {
            Union(parent, up, vp);
            ans += B[i][2];
        }
    }

    return ans;
}

