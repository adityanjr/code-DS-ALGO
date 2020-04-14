//  https://www.interviewbit.com/problems/rotated-sorted-array-search/

int pivotFind(const vector<int> &A){
    int l = 0;
    int r = A.size()-1;
    int n = A.size();
   
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        int next = (mid+1)%n;
        int prev = (mid-1+n)%n;
        if(A[l]<=A[r])
            return l;
        else if((A[mid]<=A[prev]) && (A[mid]<=A[next]))
            return mid;
        else if(A[mid]<=A[r])
            r = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int bSearch(const vector<int> &A, int B, int l, int r)
{
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

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int l = 0, r = A.size()-1;
    int pivot = pivotFind(A);
    if(A[pivot]==B)
        return pivot;
    int index = bSearch(A, B, 0, pivot-1);
    if(index==-1)
        index = bSearch(A, B, pivot, A.size()-1);
    return index;
    
}
