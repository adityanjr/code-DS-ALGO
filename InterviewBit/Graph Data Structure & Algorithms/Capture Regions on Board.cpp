//  https://www.interviewbit.com/problems/capture-regions-on-board/

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
void dfs(vector<vector<char> > &A, int x, int y) {
    A[x][y] = 'O';
    
    for(int i=0;i<4;i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx<0 || ny<0 || nx>=n || ny>=m)
            continue;
        
        if(A[nx][ny]=='-')
            dfs(A, nx, ny);
    }
}
void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    n = A.size();
    m = A[0].size();
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;++j)
            if(A[i][j]=='O')
                A[i][j] = '-';
    
    for(int i=0;i<n;i++) {
        if(A[i][0]=='-')
            dfs(A, i, 0);
        if(A[i][m-1]=='-')
            dfs(A, i, m-1);
    }
    
    for(int j=0;j<m;++j) {
        if(A[0][j]=='-')
            dfs(A, 0, j);
        if(A[n-1][j]=='-')
            dfs(A, n-1, j);
    }
    
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(A[i][j]=='-')
                A[i][j] = 'X';
    
}

