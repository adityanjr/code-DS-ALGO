//  https://www.interviewbit.com/problems/valid-path/

int mat[101][101];
bool vis[101][101];
int n, m;
int dr[] = {-1, -1, 0, 1, 1, 0, -1, 1};
int dc[] = {0, -1, -1, 0, 1, 1, 1, -1};
bool Utility(int x, int y, int r, int c) {
    if(r==x && c==y)
        return true;
        
    vis[r][c] = true;
    
    for(int i=0;i<8;i++) {
        int nr = r+dr[i];
        int nc = c+dc[i];
        if(nr<0 || nc<0 || nr>x || nc>y)
            continue;
        if(vis[nr][nc] || mat[nr][nc]==-1)
            continue;
        if(Utility(x, y, nr, nc))
            return true;
    }
    return false;
}
string Solution::solve(int x, int y, int N, int R, vector<int> &A, vector<int> &B) {
    
    n = x+1;
    m = y+1;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            mat[i][j] = 0;
            vis[i][j] = false;
        }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(int k=0;k<N;k++) {
                int pr = pow(A[k]-i, 2)+pow(B[k]-j, 2);
                if(pr<=R*R)
                    mat[i][j] = -1;
            }
        }
    }
    

    
    if(mat[0][0]==-1 || mat[x][y]==-1)
        return "NO";
    vis[0][0] = true;
    return (Utility(x, y, 0, 0))?"YES":"NO";
}

