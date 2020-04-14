// https://www.interviewbit.com/problems/matrix-search/

int bsearch(vector<int> A, int B)
{
    int start = 0, end = A.size()-1;
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(A[mid] == B)
            return 1;
        else if(A[mid] > B)
            end = mid-1;
        else
            start = mid+1;
    }
    return 0;
}
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int m = A[0].size();
    int row;
    for(int i=0;i<n;i++)
        if(A[i][0] <= B && A[i][m-1] >= B)
        {
            row = i;
            break;
        }
    return bsearch(A[row], B);
}

