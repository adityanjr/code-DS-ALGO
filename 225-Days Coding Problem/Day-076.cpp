class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int col = static_cast<int>(A[0].size());
        int row = static_cast<int>(A.size());
        int required_deletion{};
        for ( int c{}; c < col; ++c ) {
            for ( int r{}; r < row-1; ++r ) {
                if(A[r][c] > A[r+1][c]){
                    ++required_deletion;
                    break;
                }
            }
        }
        return required_deletion;
    }
};
