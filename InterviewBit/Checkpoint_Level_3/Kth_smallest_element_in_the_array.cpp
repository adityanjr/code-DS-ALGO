//  https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/

int F(const vector<int> &A, int x) {
    int count = 0;
    for(int i=0;i<A.size();i++)
        if(A[i] <= x)
            count++;
    return count;
}
int Solution::kthsmallest(const vector<int> &A, int B) {
    int n = A.size();
    
    int start = A[0], end = A[0], mid;
    for(auto a: A) {
        start = min(a, start);
        end = max(a, end);
    }
    if(n<=B)
        return end;
    else if(B==1)
        return start;
    
    int reqN;
    while(end-start > 1) {
        mid = (end+start)>>1;
        int count = F(A, mid);
        
        if(count==B) {
            reqN = mid;
            break;
        }
        else if(count > B) {
            end = mid;
            reqN = mid;
        }
        else
            start = mid;
    }
    
    int ans = INT_MIN;
    
    for(int i=0;i<n;i++) {
        if(A[i] <= reqN)
            ans = max(ans, A[i]);
    }
    return ans;
}

