//  https://www.interviewbit.com/problems/black-shapes/

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
int n, m;
void dfs(int r, int c, vector<string> &A, vector<vector<bool> > &vis) {
    vis[r][c] = true;
    
    for(int i=0;i<4;++i) {
        int nr = r+dr[i];
        int nc = c+dc[i];
        if(nr<0 || nc<0 || nr>=n || nc>=m)
            continue;
        if(vis[nr][nc] ||  A[nr][nc]=='O')
            continue;
        dfs(nr, nc, A, vis);
    }
}
int Solution::black(vector<string> &A) {
    n = A.size();
    m = A[0].size();
    int ans = 0;
    vector<vector<bool> > vis(n, vector<bool> (m, false));
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!vis[i][j] && A[i][j]=='X') {
                dfs(i, j, A, vis);
                ans++;
            }
        }
    }
    return ans;
}


