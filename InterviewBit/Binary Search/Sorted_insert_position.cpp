//  https://www.interviewbit.com/problems/sorted-insert-position/

int bSearch(vector<int> &A, int B)
{
    int l = 0, r = A.size()-1;
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(A[mid]==B)
            return mid;
        else if(A[mid]>B)
            r = mid-1;
        else
            l = mid+1;
    }
    return -1;
}
int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int index = bSearch(A, B);
    if(index==-1)
    {
        int l = 0, r = A.size()-1;
        if(A[l]>B)
            return 0;
        else if(A[r]<B)
            return r+1;
        else
        {
            while(l<=r)
            {
                int mid = l+(r-l)/2;
                if(A[mid-1]<B && A[mid]>B)
                    return mid;
                else if(A[mid]>B)
                    r = mid-1;
                else
                    l = mid+1;
            }
        }
    }
    return index;
}

