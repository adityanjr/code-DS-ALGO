//  https://www.interviewbit.com/problems/set-matrix-zeros/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    int m = A[0].size();

    int r=1, c=1;

    for(int j=0;j<m;j++)
        if(A[0][j]==0)
            r=0;

    for(int i=0;i<n;i++)
        if(A[i][0]==0)
            c=0;

    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(A[i][j]==0) {
                A[i][0] = 0;
                break;
            }
        }
    }

    for(int j=1;j<m;j++) {
        for(int i=0;i<n;i++) {
            if(A[i][j]==0) {
                A[0][j] = 0;
                break;
            }

        }
    }
    // set rows to zero
    for(int i=1;i<n;i++) {
        if(A[i][0]==0) {
            for(int j=1;j<m;j++)
                A[i][j] = 0;
        }
    }
    // set columns to zero
    for(int j=1;j<m;j++) {
        if(A[0][j]==0) {
            for(int i=1;i<n;i++)
                A[i][j] = 0;
        }
    }


    if(r==0)
        for(int j=0;j<m;j++)
            A[0][j] = 0;
    if(c==0)
        for(int i=0;i<n;i++)
            A[i][0] = 0;
    
}

