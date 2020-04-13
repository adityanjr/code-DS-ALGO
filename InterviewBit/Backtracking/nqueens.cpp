//  https://www.interviewbit.com/problems/nqueens/

vector<string> toString(const vector<int> &board) {
    int n = board.size();
    vector<string> A(n);

    for(int i=0;i<n;i++) {
        A[i] = string(n, '.');
        A[i][board[i]] = 'Q';
    }
    return A;
}
bool isSafe(int col, int row, const vector<int> &board) {
    for(int queen=0;queen<row;queen++)
        if(board[queen]==col || queen-board[queen]==row-col || queen+board[queen]==row+col)
            return false;
    return true;
}
void solveNQueensUtil(int row, vector<int> &board, vector<vector<string> > &result) {
    int A = board.size();
    if(row==A) {
        result.push_back(toString(board));
        return;
    }

    for(int col=0;col<A;col++) {
        if(isSafe(col, row, board)) {
            board[row] = col;
            solveNQueensUtil(row+1, board, result);
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string> > boards;
    vector<int> board(A);
    
    solveNQueensUtil(0, board, boards);
    
    return boards;
}

