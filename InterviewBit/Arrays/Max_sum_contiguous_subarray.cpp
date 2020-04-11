//  https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
 int max(int x,int y) {
     return (x>y)?x:y;
 }
int maxSubArray(const int* A, int n1) {
    
    int curr_max=A[0];
    int max_so_far=A[0];
    int i;
    
    for(i=1;i<n1;i++) {
        
        curr_max=max(curr_max+A[i],A[i]);
        max_so_far=max(curr_max,max_so_far);
        
    }
    return max_so_far;
}

