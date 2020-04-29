//  https://www.interviewbit.com/problems/minimize-the-absolute-difference/#

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    auto min_diff = INT_MAX;
    
    for(int i=0;i<A.size();i++) {
        int j = 0, k = 0;
        while(1) {
            int min_num = min(A[i], min(B[j], C[k]));
            int max_num = max(A[i], max(B[j], C[k]));
            min_diff = min((max_num - min_num), min_diff);
            if(B[j]==min_num)
                j++;
            else if(C[k]==min_num)
                k++;
            else 
                break;
            if(j==B.size() || k==C.size())
                break;
        }
    }
    return min_diff;
}
