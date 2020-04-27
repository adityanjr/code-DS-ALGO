//  https://www.interviewbit.com/problems/3-sum/

int Solution::threeSumClosest(vector<int> &A, int B) {
    
    int n = A.size();
    int minDiff = INT_MAX;
    int bestSum = 0;
    sort(A.begin(), A.end());
    
    for(int i=0;i<n-2;i++) {
        
        int j=i+1;
        int k=n-1;
        while(j<k) {
            int sum = A[i]+A[j]+A[k];
            if(minDiff > abs(sum-B)) {
                minDiff = abs(sum-B);
                bestSum = sum;
            }
            if(sum==B)
                return bestSum;
            else if(sum > B) 
                k--;
            else
                j++;
        }
    }
    return bestSum;
}

