int getPos(int A[MAX][MAX], int row, int start, int end){
    int one = end+1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(A[row][mid] == 1){
            end = mid-1;
            one = mid;
        }
        else{
            start = mid+1;
        }
    }
    
    return one;
}

/*you are required to complete this method*/
int countZeroes(int A[MAX][MAX],int N)
{
//Your code here
    int ans = 0, end = N-1;
    
    for(int i = 0; i < N; i++){
        int onePos = getPos(A, i, 0, end);
        ans = ans + onePos;
        end = onePos - 1;
    }
    
    return ans;
}
