//  https://www.interviewbit.com/problems/counting-triangles/

int Solution::nTriang(vector<int> &A) {
    sort(A.begin(), A.end());
    long long int d = pow(10, 9);
    
    int count = 0;
    int n = A.size();
    for(int i=0;i<n-2;i++) {
        int j = i+1;
        int k = j+1;
        while(j<n-1) {
            
            while(k<n) {
                int sum = A[i]+A[j];
                if(sum<=A[k])
                    break;
                k++;
            }
            count += k-j-1;
            count = count % (d+7);
            j++;
        }
    }
    return count;
}

