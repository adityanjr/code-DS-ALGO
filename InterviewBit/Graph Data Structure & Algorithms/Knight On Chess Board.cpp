//  https://www.interviewbit.com/problems/knight-on-chess-board/

struct cell {
    int row, col, dis;
    cell(int r, int c, int dis): row(r), col(c), dis(dis) {};
};

bool isIn(int r, int c, int N, int M) {
    if((r>=1 && r<=N) && (c>=1 && c<=M))
        return true;
    return false;
}

int Solution::knight(int A, int B, int r1, int c1, int r2, int c2) {
    int dr[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int dc[] = {1, -1, -2, -2, -1, 1, 2, 2};
    
    bool visited[A+1][B+1];
    memset(visited, false, sizeof(visited));
    visited[r1][c1] = true;
    queue<cell*> q;
    cell *t = new cell(r1, c1, 0);
    q.push(t);
    
    int next_r, next_c;
    
    while(!q.empty()) {
        t = q.front();
        q.pop();
        
        if(t->row==r2 && t->col==c2)
            return t->dis;
        for(int i=0;i<8;i++) {
            next_r = t->row+dr[i];
            next_c = t->col+dc[i];
            
            if(isIn(next_r, next_c, A, B) && !visited[next_r][next_c]) {
                cell * st = new cell(next_r, next_c, t->dis+1);
                visited[next_r][next_c] = true;
                q.push(st);
            }
        }
    }
    return -1;
}

