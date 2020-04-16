//  https://www.interviewbit.com/problems/jump-game-array/

int Solution::canJump(vector<int> &A) {
    
    int n = A.size();
    int mip = n-1;
    
    for(int i=n-2;i>=0;i--) {
        bool ans = false;
        
        if(i+A[i] >= mip) {
            mip = i;
            ans = true;
        }
        
        if(i==0)
            return ans;
    }
    return true;
}

